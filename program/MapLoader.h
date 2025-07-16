#pragma once
#include<vector>
#include<string>
#include"MapTile.h"


using MapTiles = std::vector<std::vector<MapTile>>;

class MapLoader {
	static std::vector<MapTile> split(const std::string& str, char delimiter = ',');
	static bool CheckCollision(int arg_id);
public:
	static MapTiles Load(const std::string& mapDataFilePath);
};