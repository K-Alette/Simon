#pragma once
#ifndef __GameState__
#define __GameState__

#include <string>
#include <iostream>

class GameState
{
protected:
	std::vector<std::string> m_textureIDList;

public:
	virtual void update() = 0;
	virtual void render() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual std::string getStateID() const = 0;
};

#endif // __GameState__