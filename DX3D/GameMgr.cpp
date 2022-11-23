#include "Framework.h"

#include "Scenes/Tutorial_Scene.h"

GameMgr::GameMgr()
{
	Create();

	scene = new Tutorial_Scene();
}

GameMgr::~GameMgr()
{
	delete scene;
}

void GameMgr::Update()
{
	scene->Update();
}

void GameMgr::Render()
{
	Device::Get()->Clear();

	scene->Render();
	scene->GUIRender();

	Device::Get()->Present();
}

void GameMgr::Create()
{
	Device::Get();
}

void GameMgr::Delete()
{
	Device::Delete();
	Shader::Delete();
}