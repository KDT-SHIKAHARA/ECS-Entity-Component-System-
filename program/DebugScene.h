#pragma once
#include"sceneBase.h"

/// <summary>
/// デバック用スクリーン
/// </summary>
class SceneDebug :public Scene{


public:
	SceneDebug();
	void Update()override;
	void Render()override;
};