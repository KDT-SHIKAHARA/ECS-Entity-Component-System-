#pragma once

/// <summary>
/// 1タイルのクラス
/// タイルのマップ番号と当たり判定を行うかどうかのフラグを持つ
/// </summary>
struct MapTile{
	int tileID_;	//	マップの番号
	bool isCollision_;	//	当たり判定するかどうか
	MapTile(int arg_tileID = 0,bool arg_isCollision =false)
		:tileID_(arg_tileID), isCollision_(arg_isCollision){}
};