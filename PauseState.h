#pragma once

#ifndef __PauseState__
#define __PauseState__

#include <string>
#include <vector>

#include "MenuState.h"

class GameObjects;

class PauseState : public MenuState
{
private:

	virtual void setCallbacks(const std::vector<Callback>& callbacks);

	static void s_pauseToMain();
	static void s_resumePlay();

	static const std::string s_pauseID;

	std::vector<GameObjects*> m_gameObjects;

public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_pauseID; }

};

#endif // __PauseState__