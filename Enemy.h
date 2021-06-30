#pragma once
#include "SDLGO.h"

class Enemy : public SDLGO //inherit from SDLGO
{
public:
	Enemy(const LoaderParams* Params);

	virtual void draw();
	virtual void update();
	virtual void clean();

};