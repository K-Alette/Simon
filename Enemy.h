#pragma once
#ifndef __Enemy__
#define __Enemy__
#include <string>
#include "SDLGO.h"
#include "GOFactory.h"

class Enemy : public SDLGO //inherit from SDLGO
{
public:
	Enemy();

	void draw();
	void update();
	void clean();
	virtual void load(const LoaderParams* Params);


};

class EnemyCreator : public BaseCreator //enemy object creator derived from BaseCreator class
{
	GameObjects* createGameObject() const
	{
		return new Enemy();
	}
};

#endif // __Enemy__