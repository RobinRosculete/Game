#pragma once

#include<stdint.h>
#include"ScreenBuffer.h"
#include"Color.h"
#include<iostream>
#include"Vec2D.h"
#include "Line2D.h"
using namespace std;


struct SDL_Window;

class Screen
{
public:
	Screen();
	~Screen();

	SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag);
	void swapScreen();
	

	//inline void SetClearColor(const Color& clearColor) { mClearColor = clearColor;}
	inline uint32_t Width() const { return mWidth;}
	inline uint32_t Height()const { return mHeight;}

	//Draw functioons go hear
	void Draw(int x, int y, const Color& color);
	void Draw(const Vec2D& point, const Color& color);
	void Draw(const Line2D& line, const Color& color);


private:
Screen(const Screen& screen);
Screen& operator=(const Screen& screen);
void ClearScreen();
uint32_t mWidth;
uint32_t mHeight;
Color mClearColor;
SDL_Window* moptrWindow;
ScreenBuffer mBackBuffer;
SDL_Surface * mnoptrWindowsSurface;
};

