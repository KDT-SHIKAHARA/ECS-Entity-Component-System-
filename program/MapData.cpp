#include "MapData.h"
#include<stdexcept>


/// <summary>
/// �t�@�C���Ǎ��N���X�̓Ǎ����\�b�h������āA�}�b�v�f�[�^����ꂽTiles�^�̃I�u�W�F�N�g��Ԃ�
/// </summary>
/// <param name="filePath"> �}�b�v�f�[�^�������Ă���t�@�C�� </param>
void MapData::LoadMapData(const std::string& filePath){
	//	�Ǎ����\�b�h

	//	�T�C�Y�擾
	if (!tiles_.empty()) return;
	map_max_w_ = tiles_[0].size();
	map_max_h_ = tiles_.size();
}

/// <summary>
/// �w�肵���C���f�b�N�X�̃^�C����const�Q�Ƃ�Ԃ��B
/// �C���f�b�N�X���͈͊O�Ȃ�@�f�o�b�N�i�K�ł̓G���[��f������B���i��Ԃƃf�o�b�N��ԂŐ؂�ւ���
/// </summary>
/// <param name="arg_x"> ���v�f���̃C���f�b�N�X </param>
/// <param name="arg_y"> ���v�f���̃C���f�b�N�X </param>
/// <returns></returns>
const Tile& MapData::GetTile(int arg_x, int arg_y) const {
	if (arg_x < 0 || arg_y < 0 || arg_x >= map_max_w_ || arg_y >= map_max_h_) throw std::out_of_range("MapData::GetTile index over ");

}
