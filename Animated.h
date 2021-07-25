#pragma once
#ifndef __Animated__
#define __Animated__

#include "SDLGO.h"
#include "LoaderParams.h"
#include "GOFactory.h"

class Animated : public SDLGO
{
public:

	Animated();

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);

private:
	int m_animSpeed;
};

class AnimatedGraphicCreator : public BaseCreator
{
public:
	GameObjects* createGameObject() const
	{
		return new Animated();
	}
};


#endif /* defined(__Animated__) */