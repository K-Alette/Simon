#pragma once
#ifndef __GameObjects__
#define __GameObjects__

#include "LoaderParams.h"

//abstract class - reusable code for game objects

class GameObjects
{
protected:
	GameObjects() {}
	virtual ~GameObjects() {}

public:

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual void load(const LoaderParams* pParams) = 0;

};

#endif // __GameObjects__