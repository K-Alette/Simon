#pragma once
#include <iostream>
#include <map>
#include "SDL.h"
#include <SDL_image.h>

class TextureManager
{
private:
	static TextureManager* inst;

	std::map<std::string, SDL_Texture*> m_textureMap;

	//private constructor so this class will only have one instance
	TextureManager() {} 
	~TextureManager() {}

public:
	static TextureManager* Instance()
	{
		if (inst == 0)
		{
			inst = new TextureManager();
			return inst;
		}

		return inst;
	}

	void clearFromTextureMap(std::string id);

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	//draw
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//draw frame
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//map of pointers to texture objects using strings
	std::map<std::string, SDL_Texture*>textureMap;
};

typedef TextureManager TheTextureManager;