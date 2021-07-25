#pragma once

#ifndef __GameOverState__
#define __GameOverState__

#include <vector>
#include <string>

#include "MenuState.h"

class GameObjects;

class GameOverState : public MenuState
{
private:
	virtual void setCallbacks(const std::vector<Callback>& callbacks);

	static void s_gameOverToMain();
	static void s_restartPlay();

	static const std::string s_gameOverID;

	std::vector<GameObjects*> m_gameObjects;

public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_gameOverID; }

};

#endif // __GameOverState__