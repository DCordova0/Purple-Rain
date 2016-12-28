#include "Drop.h"
#include "main.h"

Drop::Drop(float _x, float _y, float k) {
	x = _x;
	y = _y;
	w = k;
	h = k*6;
	vel = k*3;
}

void Drop::update() {
	this->y += this->vel;
}

void Drop::draw(SDL_Renderer *renderer) {
	SDL_Rect dest;
	dest.x = this->x;
	dest.y = this->y;
	dest.w = this->w;
	dest.h = this->h;
	SDL_SetRenderDrawColor( renderer, 102, 0, 102, 255 ); //PURPLE
	SDL_RenderFillRect( renderer, &dest );
}

bool Drop::out() {
	if (this->y > SCREEN_HEIGHT)
		return true;
	else
		return false;
}