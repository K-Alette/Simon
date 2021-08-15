#pragma once
#ifndef __Background__
#define __Background__
#include "SDLGO.h"
#include "GOFactory.h"

//class to render the background for the game

class Background : public SDLGO //inherit from GameObjects
{

public:

	Background();

	void draw();
	void update();
	void load(const LoaderParams* Params);

};

class BackgroundCreator : public BaseCreator
{
public:
	GameObjects* createGameObject() const
	{
		return new Background();
	}
};

#endif // __Background__