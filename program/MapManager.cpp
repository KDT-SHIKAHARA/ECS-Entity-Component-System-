#include"MapManager.h"
#include"Rect.h"


/// <summary>
/// �}�b�v�Ƃ̓����蔻����s���B
/// </summary>
/// <param name="gameObj"></param>
void MapManager::CheckCollision(const GameObject& gameObj){
	//	�v���C���[�̍��W

	//	�v���C���[�̃T�C�Y

	//	�}�b�v�^�C���̃T�C�Y



	//	�v���C���[�̎l�_�̃}�b�v�ԍ�

	//	�}�b�v�O�Ȃ�}�b�v�̐����ɂ���B

	//	�}�b�v���̐����œ����蔻��
}

/// <summary>
/// �t�@�C������t�@�C���p�X��ǂݍ����
/// �t�@�C������摜��ǂݍ���
/// </summary>
void MapManager::Load() {
	//	�t�@�C���p�X��ǂݍ���
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
/// �`��
/// </summary>
/// <param name="camera"> �J�����N���X�̍��W���擾 </param>
void MapManager::Render(const Camera& camera) {
	try
	{
		//	�`��
		render.Render(mapData, camera);

	}
	catch (const std::exception&)
	{
		
	}
}