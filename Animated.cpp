#include "SDL.h"
#include "Animated.h"

Animated::Animated() : SDLGO() {}

void Animated::draw()
{
	SDLGO::draw();
}

void Animated::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % 2));
}

void Animated::clean() {}

void Animated::load(const LoaderParams* pParams)
{
	SDLGO::load(pParams);
	m_animSpeed = pParams->getAnimSpeed();
}