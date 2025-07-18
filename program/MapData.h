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
	MapData() = default;
	virtual ~MapData() = default;

	//	マップデータの読込
	void LoadMapData(const std::string& filePath);

	//	タイルの参照を取得（変更不可）
	const Tile& GetTile(int arg_x, int arg_y) const ;

	//	マップサイズの取得
	int GetMapW()const { return map_max_w_; }
	int GetMapH()const { return map_max_h_; }


private:

	//	.size()で取得してるとメソッド呼び出しのコストがかかるので、
	//	ファイルから読み込んだ時点で確定してるのでフィールドを作ったほうが効率がいい
	int map_max_w_;	//	マップの横の最大数
	int map_max_h_;	//	マップの縦の最大数

	Tiles tiles_;	//	タイルのコレクション
};