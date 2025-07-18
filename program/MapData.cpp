#include "MapData.h"
#include<stdexcept>


/// <summary>
/// ファイル読込クラスの読込メソッドを作って、マップデータを入れたTiles型のオブジェクトを返す
/// </summary>
/// <param name="filePath"> マップデータが入っているファイル </param>
void MapData::LoadMapData(const std::string& filePath){
	//	読込メソッド

	//	サイズ取得
	if (!tiles_.empty()) return;
	map_max_w_ = tiles_[0].size();
	map_max_h_ = tiles_.size();
}

/// <summary>
/// 指定したインデックスのタイルのconst参照を返す。
/// インデックスが範囲外なら　デバック段階ではエラーを吐かせる。製品状態とデバック状態で切り替える
/// </summary>
/// <param name="arg_x"> 第二要素数のインデックス </param>
/// <param name="arg_y"> 第一要素数のインデックス </param>
/// <returns></returns>
const Tile& MapData::GetTile(int arg_x, int arg_y) const {
	if (arg_x < 0 || arg_y < 0 || arg_x >= map_max_w_ || arg_y >= map_max_h_) throw std::out_of_range("MapData::GetTile index over ");

}
