#include "SDL.h"
#include "SDLGO.h"
#include "Fruit.h"

Fruit::Fruit() : SDLGO() {}

void Fruit::draw()
{
	SDLGO::draw();
}

void Fruit::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));

	if (m_position.getY() == 0)
	{
		m_velocity.setY(2);
	}
	else if (m_position.getY() > 350)
	{
		m_velocity.setY(0);
	}

	SDLGO::update();
}

void Fruit::clean() {}

void Fruit::load(const LoaderParams* Params)
{
	SDLGO::load(Params);
}