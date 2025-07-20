#pragma once
#include<string>
#include<vector>
#include"Tile.h"

class MapLoader {
	static std::vector<Tile> split(const std::string& str, char delimiter = ',');
	static bool CheckCollisionFlag(int map_num);
public:
	static std::vector<std::vector<Tile>> Load(const std::string& filepath);
};