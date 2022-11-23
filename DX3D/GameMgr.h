#pragma once

class GameMgr
{
public:
	GameMgr();
	~GameMgr();

	void Update();
	void Render();

private:
	void Create();
	void Delete();

private:
	Scene* scene;
};