#pragma once
#ifndef __PlayState__
#define __PlayState__

#include <vector>
#include "GameState.h"

class GameObjects;
class SDLGO;

class PlayState : public GameState
{
private:
	static const std::string s_playID;

	std::vector<GameObjects*> m_gameObjects;

	bool checkCollision(SDLGO* p1, SDLGO* p2);

public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }
};

#endif // __PlayState__