#pragma once
#include<string>
#include<vector>
#include<memory>
#include"TextureResource.h"
#include"MapTile.h"
#include"vector2d.h"


class MapDrawer {
public:
	void LoadTiles(const std::string& directory, int arg_tileCount);
	void DrawTiles(
		const std::vector<std::vector<MapTile>>& arg_map,
		const Vector2D<float>& arg_camera,
		int tileSize)const;

private:
	std::vector<std::shared_ptr<TextureResource>> textures_;
};