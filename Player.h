#pragma once
#include "SDLGO.h"

class Player : public SDLGO //inherit from GameObjects
{
public:

	Player(const LoaderParams* Params);

	void draw();
	void update();
	void clean();

};