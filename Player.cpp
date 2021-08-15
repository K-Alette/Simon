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

	//update player position for jumping
	if (m_position.getY() == 280)
	{
		m_velocity.setY(2);
	}
	if (m_position.getY() == 340 && m_velocity.getY() == 2)
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
	//check if player is pressing keys and set velocity of player accordingly
	if (IH::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		m_velocity.setX(-2);
	}
	if (IH::Instance()->isKeyDown(SDL_SCANCODE_D))
	{
		m_velocity.setX(2);
	}
	else if (IH::Instance()->isKeyDown(SDL_SCANCODE_A) == false && IH::Instance()->isKeyDown(SDL_SCANCODE_D) == false)
	{
		m_velocity.setX(0);
	}
	//for jumping
	if (IH::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && m_position.getY() == 340)
	{
		m_velocity.setY(-2);
	}

}

void Player::load(const LoaderParams* Params)
{
	SDLGO::load(Params);
}