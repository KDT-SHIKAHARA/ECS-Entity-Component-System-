#pragma once
#include<vector>
#include<string>
#include"Tile.h"

/// <summary>
/// �}�b�v�f�[�^�̓Ǎ��ƃ}�b�v�f�[�^�̒��g�������Ă���Tile�N���X�̃R���N�V�����̊Ǘ�
/// </summary>
class MapData final{
	//	�ʃG���A�X
	using Tiles = std::vector<std::vector<Tile>>;

public:
	MapData() = default;
	virtual ~MapData() = default;

	//	�}�b�v�f�[�^�̓Ǎ�
	void LoadMapData(const std::string& filePath);

	//	�^�C���̎Q�Ƃ��擾�i�ύX�s�j
	const Tile& GetTile(int arg_x, int arg_y) const ;

	//	�}�b�v�T�C�Y�̎擾
	int GetMapW()const { return map_max_w_; }
	int GetMapH()const { return map_max_h_; }


private:

	//	.size()�Ŏ擾���Ă�ƃ��\�b�h�Ăяo���̃R�X�g��������̂ŁA
	//	�t�@�C������ǂݍ��񂾎��_�Ŋm�肵�Ă�̂Ńt�B�[���h��������ق�������������
	int map_max_w_;	//	�}�b�v�̉��̍ő吔
	int map_max_h_;	//	�}�b�v�̏c�̍ő吔

	Tiles tiles_;	//	�^�C���̃R���N�V����
};