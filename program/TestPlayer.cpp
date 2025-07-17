#include "TestPlayer.h"
#include"RigidbodyComp.h"
#include"dxlib.h"
#include"GetColor.h"
#include"input.h"
#include"debugLog.h"

void TestPlayer::SetComponents(){
	auto rigid =  AddComponent<RigidbodyComp>(1.0f);
	DebugLog::AddDubug("rigid.isGravity", rigid->isGravity_);
	transform.AddDebugLog();
	transform.SetPosition(Vector2D<float>(500, 0));
}

void TestPlayer::Update(){
	GameObject::Update();
	
	//	切り替えできるかデバック用
	if (Input::IsKeyOn(KEY_INPUT_1)) {
		auto input = GetComponent<RigidbodyComp>();
		input->isGravity_.Toggle();
	}
}

void TestPlayer::Render(){
	const auto& pos = transform.WorldPosition();
	DrawCircleAA(pos.x, pos.y, 50, 20, GREEN, TRUE);
	GameObject::Render();
}
