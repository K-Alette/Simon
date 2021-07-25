#include "SDLGO.h"
#include "TextureManager.h"
#include "Game.h"

//get all needed information to render game objects
SDLGO::SDLGO() : GameObjects(), m_position(0, 0), m_velocity(0, 0), m_acceleration(0, 0) {}

//load game object
void SDLGO::load(const LoaderParams* Params)
{
	m_position = Vector(Params->getX(), Params->getY());
	m_velocity = Vector(0, 0);
	m_acceleration = Vector(0, 0);
	m_width = Params->getWidth();
	m_height = Params->getHeight();
	m_textureID = Params->getTextureID();

	m_currentRow = 1;
	m_currentFrame = 1;
}

//draw game objects
void SDLGO::draw()
{
	if (m_velocity.getX() > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Simon::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}
	else
	{
		TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Simon::Instance()->getRenderer());
	}
}

//updating game objects (adding vectors)
void SDLGO::update()
{
	m_position += m_velocity;
	m_velocity += m_acceleration;
}

void SDLGO::clean() {}