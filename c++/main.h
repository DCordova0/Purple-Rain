#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();



#endif // MAIN_H