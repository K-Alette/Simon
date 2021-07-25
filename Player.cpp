#include <string>
#include "SDL.h"
#include "Player.h"
#include "Input.h"

Player::Player() : SDLGO() {}

void Player::draw()
{
	SDLGO::draw();
}

void Player::update()
{
	handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));

	if (m_position.getY() == 330)
	{
		m_velocity.setY(2);
	}
	if (m_position.getY() == 380 && m_velocity.getY() == 2)
	{
		m_velocity.setY(0);
	}

	SDLGO::update();
}

void Player::clean()
{}

void Player::handleMovement(Vector velocity)
{
	Vector newPos = m_position;

}

void Player::handleInput()
{
	/*Vector* target = IH::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;*/

	if (IH::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		m_velocity.setX(-2);
	}
	if (IH::Instance()->isKeyDown(SDL_SCANCODE_D))
	{
		m_velocity.setX(2);
	}
	if (IH::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && m_position.getY() == 380)
	{
		m_velocity.setY(-2);
	}

}

void Player::load(const LoaderParams* Params)
{
	SDLGO::load(Params);
}