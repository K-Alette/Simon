#include "SDL.h"
#include "Enemy.h"

Enemy::Enemy() : SDLGO() {}

void Enemy::draw()
{
	SDLGO::draw();
}

void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));

	if (m_position.getX() < 0)
	{
		m_velocity.setX(2);
	}
	else if (m_position.getX() > 600)
	{
		m_velocity.setX(-2);
	}

	SDLGO::update();
}

void Enemy::clean() {}

void Enemy::load(const LoaderParams* Params)
{
	SDLGO::load(Params);
	m_velocity.setX(2);
}