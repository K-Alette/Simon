#include <string>
#include "SDL.h"
#include "Background.h"
#include "Input.h"

Background::Background() : SDLGO() {}

void Background::draw()
{
	SDLGO::draw();
}

void Background::load(const LoaderParams* Params)
{
	SDLGO::load(Params);
}

void Background::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));

	SDLGO::update();
}