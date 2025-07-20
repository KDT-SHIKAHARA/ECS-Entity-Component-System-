#pragma once
#include"vector2d.h"

class Camera {
	Vector2D<float> position_;
public:
	Vector2D<float> position()const { return position_; }
};