#include "DebugScene.h"
#include "debugDef.h"
#include "DebugLog.h"





SceneDebug::SceneDebug(){
	auto player = std::make_shared<TestPlayer>();
	player->SetComponents();
	testPlayer = player;
}

void SceneDebug::Update(){
	testPlayer->Update();
}

void SceneDebug::Render()
{
	DEBUG_LOG("debug scene");
	testPlayer->Render();
}
