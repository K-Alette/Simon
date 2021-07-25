#pragma once
#ifndef __MenuButton__
#define __MenuButton__

#include "LoaderParams.h"
#include "SDLGO.h"
#include "GOFactory.h"

class MenuButton : public SDLGO
{
private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	void(*m_callback)();
	bool m_bReleased;
	int m_callbackID;

public:

	MenuButton();

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);
	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }


};

class MenuButtonCreator : public BaseCreator
{
	GameObjects* createGameObject() const
	{
		return new MenuButton();
	}
};

#endif // __MenuButton__