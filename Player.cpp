#include "Player.h"

Player::Player(const LoaderParams* Params) : SDLGO(Params)
{

}

void Player::draw()
{
	SDLGO::draw();
	//GameObjects::draw(pRenderer);
}

void Player::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_acceleration.setX(1); //add 1 to x position
	SDLGO::update();
}

void Player::clean()
{

}