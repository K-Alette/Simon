#pragma once
#include <iostream>
#include "TextureManager.h"
#include "LoaderParams.h"

//abstract class - reusable code for game objects

class GameObjects
{
protected:
	GameObjects(const LoaderParams* Params) {}
	virtual ~GameObjects() {}

public:

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

};