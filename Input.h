#pragma once
#include "SDL.h"
#include "Vector.h"

class InputHandler
{
private:
	InputHandler();
	~InputHandler() {}

	static InputHandler* Inst;

	//keyboard events
	void onKeyDown();
	void onKeyUp();

	const Uint8* keystates;

public:
	static InputHandler* Instance()
	{
		if (Inst == 0)
		{
			Inst = new InputHandler();
		}

		return Inst;
	}

	void update();

	bool isKeyDown(SDL_Scancode key);
};

typedef InputHandler IH;