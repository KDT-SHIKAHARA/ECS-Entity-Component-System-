#pragma once
#include"sceneBase.h"
#include"TestPlayer.h"

/// <summary>
/// �f�o�b�N�p�X�N���[��
/// </summary>
class SceneDebug :public Scene{
	std::shared_ptr<GameObject> testPlayer;

public:
	SceneDebug();
	void Update()override;
	void Render()override;
};