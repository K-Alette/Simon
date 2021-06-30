#include "SDLGO.h"
#include "TextureManager.h"
#include "Game.h"

//get all needed information to render game objects
SDLGO::SDLGO(const LoaderParams* Params) : GameObjects(Params), m_position(Params->getX(), Params->getY()), m_velocity(0, 0), m_acceleration(0, 0)
{
	m_width = Params->getWidth();
	m_height = Params->getHeight();
	m_textureID = Params->getTextureID();

	m_currentRow = 1;
	m_currentFrame = 1;
}

//draw game objects
void SDLGO::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer());
}

//updating game objects (adding vectors)
void SDLGO::update()
{
	m_position += m_velocity;
	m_velocity += m_acceleration;
}

void SDLGO::clean()
{

}