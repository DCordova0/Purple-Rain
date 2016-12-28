#ifndef DROP_H
#define DROP_H

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class Drop {
public:
	float x,y,w,h,vel;

	Drop(float _x, float _y, float k);
	void update();
	void draw(SDL_Renderer *renderer);
	bool out();
};

#endif // DROP_H