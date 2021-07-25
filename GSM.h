#pragma once
#ifndef __GameStateMachine__
#define __GameStateMachine__

#include <vector>

#include "GameState.h"

class GameStateMachine
{
private:
	std::vector<GameState*> m_gameStates;
	void popStatePrivate();
	void changeStatePrivate(GameState* pState);
	GameState* newState;
	bool popStateFlag;
	bool changeStateFlag;

public:

	GameStateMachine() : newState(nullptr), popStateFlag(false), changeStateFlag(false) {}
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();

	void update();
	void render();


};

#endif // __GameStateMachine__