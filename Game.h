//Game class declarations
#pragma once
#ifndef _Game_
#define _Game_
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameObjects.h"
#include <SDL_image.h>
#include <vector>

class Game
{
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	static Game* inst;

	int m_currentFrame;

	bool m_bRunning;

	Game() {} //constructor
	~Game() {} //destructor

public:

	static Game* Instance() //create instance of game
	{
		if (inst == 0)
		{
			inst = new Game();
			return inst;
		}

		return inst;
	}

	//vector to store all game objects
	std::vector<GameObjects*>gameObjects;

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	//function to return SDL_renderer obj
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	//declare functions for Game class
	void render();
	void update();
	void handleEvents();
	void clean();
	void draw();

	//quit game
	void quit() { m_bRunning = false; }

	//function to access private running variable
	bool running() { return m_bRunning; }
};

typedef Game Simon;

#endif