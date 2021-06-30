//Game class definitions - main will call these functions to create game instace
#include <iostream>
#include "Game.h"
#include "GameObjects.h"

Game* Game::inst = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) //initiate game
{
	//attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success \n";
		//init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0) //window init success
		{
			std::cout << "window creation success \n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) //renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255); //sets background color using RGBA

				//create game objects for testing
				gameObjects.push_back(new Player(new LoaderParams(200, 150, 32, 32, "animate")));
				gameObjects.push_back(new Enemy(new LoaderParams(200, 150, 32, 32, "animate")));

				//pull png file for sprite
				if (!TheTextureManager::Instance()->load("Assets/Simon/Idle.png", "animate", m_pRenderer))
				{
					return false;
				}
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; //renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; //window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; //SDL init fail
	}

	std::cout << "init success\n";
	m_bRunning = true; //everything initiated successfully, start main loop

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); //clear renderer to draw color


	//loop through objects and draw them
	for (std::vector<GameObjects*>::size_type i = 0; i != gameObjects.size(); i++)
	{
		gameObjects[i]->draw();
	}

	SDL_RenderPresent(m_pRenderer); //draw to screen
}

void Game::update()
{
	//loop through game objects and update
	for (std::vector<GameObjects*>::size_type i = 0; i != gameObjects.size(); i++)
	{
		gameObjects[i]->update();
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;
		}
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::draw()
{
	//loop through game objects vector and draw each item
	for (std::vector<GameObjects*>::size_type i = 0; i != gameObjects.size(); i++)
	{
		gameObjects[i]->draw();
	}
}