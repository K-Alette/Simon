//Game class declarations
#pragma once
#ifndef _Game_
#define _Game_
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GSM.h"
#include "MenuState.h"
#include "PlayState.h"
#include "GameObjects.h"
#include <SDL_image.h>
#include <vector>

class Game
{
private:
	Game() {} //constructor

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangele;
	SDL_Rect m_destinationRectangle;

	static Game* inst;

	int m_currentFrame;
	bool m_bRunning;
	int m_gameWidth;
	int m_gameHeight;

	//game state machine as member of game class
	GameStateMachine* m_pGameStateMachine;

public:

	~Game() {} //destructor
	
	//init function
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	static Game* Instance() //create instance of game
	{
		if (inst == 0)
		{
			inst = new Game();
			return inst;
		}

		return inst;
	}

	//declare other functions for Game class
	void render();
	void update();
	void handleEvents();
	void clean();

	//quit game
	void quit() { m_bRunning = false; }

	//function to access private running variable
	bool running() { return m_bRunning; }

	//get game state
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

	//function to return SDL_renderer obj
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	int getGameWidth() const
	{
		return m_gameWidth;
	}

	int getGameHeight() const
	{
		return m_gameHeight;
	}

};

typedef Game Simon;

#endif