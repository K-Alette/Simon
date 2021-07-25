#pragma once
#include "GameObjects.h"
#include "Vector.h"

class SDLGO : public GameObjects
{
protected:
	Vector m_position; //x, y position of objects
	Vector m_velocity; //velocity of objects
	Vector m_acceleration; //object acceleration

	int m_width;
	int m_height;

	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID; //different textures for different objects

public:
	SDLGO();

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* Params);

	Vector& getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
};
