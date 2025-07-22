#pragma once
#include"MapRender.h"
#include"MapData.h"
#include"MapResHandle.h"

class GameObject;
class MapManager {
	//	�`��
	MapRender render;

	//	�f�[�^
	MapData mapData;

	//	�n���h��
	TileTextureRegistry registry;

	//	�n���h�����i�[���Ă�t�@�C���̃p�X
	std::string handle_path_ = "res/map/handle/data.xml";
	std::string map_data_path = "res/map/data/map_data.txt";

public:
	void CheckCollision(const GameObject& gameObj);

	//	�}�b�v�f�[�^�̓Ǎ�
	void Load();

	//	�`��
	void Render(const Camera& camera);
};