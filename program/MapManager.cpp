#include"MapManager.h"
#include"Rect.h"


/// <summary>
/// マップとの当たり判定を行う。
/// </summary>
/// <param name="gameObj"></param>
void MapManager::CheckCollision(const GameObject& gameObj){
	//	プレイヤーの座標

	//	プレイヤーのサイズ

	//	マップタイルのサイズ



	//	プレイヤーの四点のマップ番号

	//	マップ外ならマップの数字にする。

	//	マップ内の数字で当たり判定
}

/// <summary>
/// ファイルからファイルパスを読み込んで
/// ファイルから画像を読み込む
/// </summary>
void MapManager::Load() {
	//	ファイルパスを読み込む
	try
	{
		registry.LoadFilesPath(handle_path_);
		render.LoadTexture(registry.tiles_file_path());
		mapData.LoadMapData(map_data_path);

	}
	catch (const std::exception&)
	{

	}

}

/// <summary>
/// 描画
/// </summary>
/// <param name="camera"> カメラクラスの座標を取得 </param>
void MapManager::Render(const Camera& camera) {
	try
	{
		//	描画
		render.Render(mapData, camera);

	}
	catch (const std::exception&)
	{
		
	}
}