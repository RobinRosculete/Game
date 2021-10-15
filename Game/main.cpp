#include <iostream>
#include <SDL.h>
#include "Color.h"
#include"Screen.h"
#include"Line2D.h"

using namespace std;
const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 488;
const int MAGNIFICATION = 2;


int main(int argc, char* argv[]) {
	Screen theScreen;
	Color color;
	Line2D line = {Vec2D(0,0), Vec2D(SCREEN_WIDTH,SCREEN_HEIGHT) };

	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
	theScreen.Draw(line, Color::Blue());
	//theScreen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Yellow());
	theScreen.swapScreen();

	SDL_Event sdlEvent;
	bool running = true; 
	while (running)
	{

		while (SDL_PollEvent(&sdlEvent)) {

			
			switch(sdlEvent.type)
			{
			case SDL_QUIT:
					running = false;
					break;
			
			}

		}

	 }

		return 0;
}

