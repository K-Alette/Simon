//Game class definitions - main will call these functions to create game instace
#include <iostream>
#include <vector>
#include "Game.h"
#include "TextureManager.h"
#include "Input.h"
#include "GSM.h"
#include "GOFactory.h"
#include "MainMenuState.h"
#include "MenuButton.h"
#include "Fruit.h"
#include "Background.h"

Game* Game::inst = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) //initiate game
{
	//attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		//init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		
		std::cout << "SDL init success \n";
		
		if (m_pWindow != 0) //window init success
		{
			std::cout << "window creation success \n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) //renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255); //sets background color using RGBA
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

	m_gameWidth = width;
	m_gameHeight = height;

	std::cout << "init success\n";
	m_bRunning = true; //everything initiated successfully, start main loop

	TheGameObjectFactory::Instance()->registerType("Background", new BackgroundCreator());
	TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
	TheGameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
	TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
	TheGameObjectFactory::Instance()->registerType("Fruit", new FruitCreator());

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MainMenuState());

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); //clear renderer to draw color

	m_pGameStateMachine->render();

	SDL_RenderPresent(m_pRenderer); //draw to screen
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	//IH = Input Handler (Input.h)
	IH::Instance()->update();

	if (IH::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::update()
{
	m_pGameStateMachine->update();
}