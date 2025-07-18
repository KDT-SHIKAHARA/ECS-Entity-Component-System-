#pragma once
#include"flag.h"
#include"MapType.h"
#include<stdexcept>


class Tile {
public:
	Tile(int arg_type_num, Flag arg_isCollision = true):isCollision_(arg_isCollision){
		if (arg_type_num >= static_cast<int>(MapType::Max)) {
			throw std::out_of_range(" arg_type_num is Over number");
		}
		type_ = static_cast<MapType>(arg_type_num);
	}
	virtual ~Tile() = default;

	//	�A�N�Z�T
	MapType GetType()const { return type_; }

private:
	MapType type_;	//	�}�b�v�f�[�^�ԍ�
public:
	Flag isCollision_;	//	�����蔻����s�����ǂ���

};

