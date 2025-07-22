#pragma once
#include"MapRender.h"
#include"MapData.h"
#include"MapResHandle.h"

class GameObject;
class MapManager {
	//	描画
	MapRender render;

	//	データ
	MapData mapData;

	//	ハンドル
	TileTextureRegistry registry;

	//	ハンドルを格納してるファイルのパス
	std::string handle_path_ = "res/map/handle/data.xml";
	std::string map_data_path = "res/map/data/map_data.txt";

public:
	void CheckCollision(const GameObject& gameObj);

	//	マップデータの読込
	void Load();

	//	描画
	void Render(const Camera& camera);
};