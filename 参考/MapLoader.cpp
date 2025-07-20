#include "MapLoader.h"
#include<sstream>
#include<fstream>

/// <summary>
/// デリミタで分解する。
/// </summary>
/// <param name="str">		 ファイルから読み込んだ文字列 </param>
/// <param name="delimiter"> 読み込む数値の前のところ	</param>
/// <returns></returns>
std::vector<MapTile> MapLoader::split(const std::string& str, char delimiter){
	std::vector<MapTile> tmp_mapLine;
	std::istringstream ss(str);
	std::string strBuf;	

	while(std::getline(ss, strBuf, delimiter)) {
		int tmp_id = std::stoi(strBuf);
		tmp_mapLine.push_back({tmp_id, CheckCollision(tmp_id)});
	}

	return tmp_mapLine;
}

/// <summary>
/// 当たり判定を行うかどうかの判定
/// </summary>
/// <param name="arg_id"> マップチップの番号 </param>
/// <returns>			  true: 当たり判定を行う false: 当たり判定をしない </returns>
bool MapLoader::CheckCollision(int arg_id){
	//	条件を描く
	return true;
}


/// <summary>
/// ファイルの読み込み
/// </summary>
/// <param name="mapDataFilePath">  </param>
/// <returns></returns>
MapTiles  MapLoader::Load(const std::string& mapDataFilePath){
	std::ifstream file(mapDataFilePath);
	MapTiles tmp_map;
	std::string line;

	while (std::getline(file, line)) {
		split(line);
	}
	return tmp_map;
}
