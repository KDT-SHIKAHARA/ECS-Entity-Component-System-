// map/Tile.h
#pragma once

enum class TileShape {
    None,
    Rect,
    Circle
};

struct Tile {
    int id = 0;
    TileShape shape = TileShape::None;
    bool isSolid = false;
};

// map/MapData.h
#pragma once
#include <vector>
#include <memory>
#include "Tile.h"

class MapData {
public:
    void LoadFromFile(const std::string& filePath);

    const Tile& GetTile(int x, int y) const;
    int GetWidth() const { return size.width; }
    int GetHeight() const { return size.height; }

private:
    struct Size {
        int width = 0;
        int height = 0;
    } size;

    std::vector<std::vector<Tile>> tiles;

    friend class MapLoader;
};

// map/MapData.cpp
#include "MapData.h"
#include "MapLoader.h"

void MapData::LoadFromFile(const std::string& filePath) {
    *this = *MapLoader::Load(filePath);
}

const Tile& MapData::GetTile(int x, int y) const {
    static Tile empty;
    if (x < 0 || y < 0 || x >= size.width || y >= size.height) return empty;
    return tiles[y][x];
}

// map/MapLoader.h
#pragma once
#include <string>
#include <memory>
#include "MapData.h"

class MapLoader {
public:
    static std::shared_ptr<MapData> Load(const std::string& xmlPath);
};

// map/MapLoader.cpp
#include "MapLoader.h"
#include <tinyxml2.h>
using namespace tinyxml2;

std::shared_ptr<MapData> MapLoader::Load(const std::string& xmlPath) {
    auto data = std::make_shared<MapData>();
    data->size.width = 10;
    data->size.height = 8;
    data->tiles.resize(data->size.height, std::vector<Tile>(data->size.width));

    for (int y = 6; y < 8; ++y) {
        for (int x = 0; x < 10; ++x) {
            data->tiles[y][x].isSolid = true;
            data->tiles[y][x].shape = TileShape::Rect;
            data->tiles[y][x].id = 1;
        }
    }
    return data;
}

// map/MapRenderer.h
#pragma once
#include "MapData.h"
#include "Camera.h"

class MapRenderer {
public:
    void Render(const MapData& map, const Camera& camera);
    void SetTileSize(float size) { tileSize = size; }

private:
    float tileSize = 32.0f;
};

// map/MapRenderer.cpp
#include "MapRenderer.h"
#include <DxLib.h>

void MapRenderer::Render(const MapData& map, const Camera& camera) {
    int width = map.GetWidth();
    int height = map.GetHeight();
    Vector2 camPos = camera.GetPosition();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const Tile& tile = map.GetTile(x, y);
            if (tile.id == 0) continue;

            float drawX = x * tileSize - camPos.x;
            float drawY = y * tileSize - camPos.y;

            int color = tile.isSolid ? GetColor(100, 100, 255) : GetColor(180, 180, 180);
            DrawBox(drawX, drawY, drawX + tileSize, drawY + tileSize, color, TRUE);
        }
    }
}

// map/MapCollider.h
#pragma once
#include "MapData.h"
#include "GameObject.h"

class MapCollider {
public:
    void ResolveCollision(GameObject& obj, const MapData& map);

private:
    bool CheckCollisionRect(const Vector2& objPos, float objW, float objH, int tileX, int tileY);
};

// map/MapCollider.cpp
#include "MapCollider.h"

void MapCollider::ResolveCollision(GameObject& obj, const MapData& map) {
    auto& tf = obj.GetTransform();
    Vector2 pos = tf.GetWorldPosition();
    float size = 32.0f;

    int tileX = static_cast<int>(pos.x / size);
    int tileY = static_cast<int>(pos.y / size);

    for (int y = tileY - 1; y <= tileY + 1; ++y) {
        for (int x = tileX - 1; x <= tileX + 1; ++x) {
            const Tile& tile = map.GetTile(x, y);
            if (!tile.isSolid) continue;

            if (CheckCollisionRect(pos, size, size, x, y)) {
                float tileLeft = x * size;
                float tileTop = y * size;
                float tileRight = tileLeft + size;
                float tileBottom = tileTop + size;

                float objLeft = pos.x;
                float objTop = pos.y;
                float objRight = objLeft + size;
                float objBottom = objTop + size;

                float dxLeft = tileRight - objLeft;
                float dxRight = objRight - tileLeft;
                float dyTop = tileBottom - objTop;
                float dyBottom = objBottom - tileTop;

                float minX = std::min(dxLeft, dxRight);
                float minY = std::min(dyTop, dyBottom);

                if (minX < minY) {
                    pos.x += (dxLeft < dxRight) ? dxLeft : -dxRight;
                } else {
                    pos.y += (dyTop < dyBottom) ? dyTop : -dyBottom;
                }
                tf.SetWorldPosition(pos);
            }
        }
    }
}

bool MapCollider::CheckCollisionRect(const Vector2& objPos, float objW, float objH, int tileX, int tileY) {
    float tileSize = 32.0f;
    float tileXf = tileX * tileSize;
    float tileYf = tileY * tileSize;

    return (objPos.x < tileXf + tileSize &&
            objPos.x + objW > tileXf &&
            objPos.y < tileYf + tileSize &&
            objPos.y + objH > tileYf);
}

// camera/Camera.h
#pragma once
#include "Vector2.h"

class Camera {
public:
    Vector2 GetPosition() const { return position; }
    void SetPosition(const Vector2& pos) { position = pos; }

private:
    Vector2 position;
};

// map/MapSystem.h
#pragma once
#include <memory>
#include "MapData.h"
#include "MapRenderer.h"
#include "MapCollider.h"
#include "GameObject.h"
#include "Camera.h"

class MapSystem {
public:
    void LoadMap(const std::string& path) {
        mapData = MapLoader::Load(path);
    }

    void Update(GameObject& obj) {
        if (mapData) {
            collider.ResolveCollision(obj, *mapData);
        }
    }

    void Render(const Camera& camera) {
        if (mapData) {
            renderer.Render(*mapData, camera);
        }
    }

    std::shared_ptr<MapData> GetMapData() const { return mapData; }

private:
    std::shared_ptr<MapData> mapData;
    MapRenderer renderer;
    MapCollider collider;
};
