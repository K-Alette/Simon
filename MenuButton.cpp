#include "MenuButton.h"
#include "Vector.h"
#include "Input.h"

MenuButton::MenuButton() : SDLGO()
{
	m_currentFrame = MOUSE_OUT; // start at frame 0
}

void MenuButton::draw()
{
	SDLGO::draw(); // use the base class drawing
}

void MenuButton::update()
{
	Vector* pMousePos = IH::Instance()->getMousePosition();

	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		if (IH::Instance()->getMouseButtonState(LEFT) && m_bReleased)
		{
			m_currentFrame = CLICKED;
			m_callback(); // call our callback function
			m_bReleased = false;
		}
		else if (!IH::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean()
{
	SDLGO::clean();
}

void MenuButton::load(const LoaderParams* pParams)
{
	SDLGO::load(pParams);
	m_callbackID = pParams->getCallbackID();
	m_currentFrame = MOUSE_OUT;
}