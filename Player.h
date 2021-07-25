#pragma once

#ifndef __Player__
#define __Player__
#include "SDLGO.h"
#include "GOFactory.h"
#include "Vector.h"

class Player : public SDLGO //inherit from GameObjects
{
private:
	void handleInput();

public:

	Player();

	void draw();
	void update();
	void clean();
	void load(const LoaderParams* Params);
	void handleMovement(Vector velocity);

};

class PlayerCreator : public BaseCreator
{
public:
	GameObjects* createGameObject() const
	{
		return new Player();
	}
};

#endif // __Player__