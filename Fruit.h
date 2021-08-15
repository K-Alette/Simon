#pragma once
#ifndef __Fruit__
#define __Fruit__
#include <string>
#include "SDLGO.h"
#include "GOFactory.h"

class Fruit : public SDLGO //inherit from SDLGO
{
public:
	Fruit();

	void draw();
	void update();
	void clean();
	virtual void load(const LoaderParams* Params);

};

class FruitCreator : public BaseCreator //enemy object creator derived from BaseCreator class
{
	GameObjects* createGameObject() const
	{
		return new Fruit();
	}
};

#endif // __Fruit__