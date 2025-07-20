#pragma once
#include<vector>
#include<string>
#include"Tile.h"

/// <summary>
/// マップデータの読込とマップデータの中身が入っているTileクラスのコレクションの管理
/// </summary>
class MapData final{
	//	別エリアス
	using Tiles = std::vector<std::vector<Tile>>;

public:
	MapData();
	virtual ~MapData() = default;

	//	マップデータの読込
	void LoadMapData(const std::string& filePath);

	//	タイルの参照を取得（変更不可）
	const Tile& GetTile(int index_x, int index_y) const ;

	//	マップサイズの取得
	int GetMapW()const { return map_max_w_; }
	int GetMapH()const { return map_max_h_; }

	//	タイルのサイズ取得
	int GetTileSize()const { return tile_size_; }

private:

	int tile_size_;

	int map_max_w_;	//	マップの横の最大数
	int map_max_h_;	//	マップの縦の最大数

	Tiles tiles_;	//	タイルのコレクション
};