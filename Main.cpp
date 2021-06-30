//main file to create instance of game and call necessary functions
#include "Game.h"

//variables for fixed frame rate
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS; //1 frame every 16.67 milliseconds

int main(int argc, char* argv[])
{
	Uint32 frameStart, frameTime;

	if (Simon::Instance()->init("Simon", 350, 180, 1280, 720, false)) //first two numbers set position on screen, second two set SDL window size
	{ 
		std::cout << "game init success!\n";    //alert for init success

		//game loop
		while (Simon::Instance()->running()) 
		{ 
			frameStart = SDL_GetTicks(); //get initial tick set frameStart to value

			Simon::Instance()->handleEvents();      
			Simon::Instance()->update();      
			Simon::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart; //subtract frameStart from current tick to get frameTime

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime)); //delay time if the frameTime is shorter than the delay time of 1000.0f / 60
			}
		} 
	}
	else 
	{ 
		std::cout << "game init failure - " << SDL_GetError() << "\n";    //alert if game could not be initiated
		return -1; 
	}  
	
	std::cout << "game closing...\n";  //alert for game closing
	Simon::Instance()->clean();  //clean game before ending program
	return 0;

}