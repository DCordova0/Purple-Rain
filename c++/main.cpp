#include "main.h"
#include "Drop.h"

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

SDL_Renderer* background = NULL;

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( 
			"SDL Tutorial", 
			SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, 
			SCREEN_WIDTH, 
			SCREEN_HEIGHT, 
			SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
			background = SDL_CreateRenderer( gWindow, -1, 0);
			if (background == NULL) {
				cout << "Could not create render" << endl;
			}
		}
	}



	return success;
}

void close()
{

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main( int argc, char* args[] )
{

	vector<Drop> drops;

	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{

		
		//Main loop flag
		bool quit = false;
		bool paused = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while( !quit )
		{
			//Handle events on queue
			while( SDL_PollEvent( &e ) != 0 )
			{
				//User requests quit
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}

				if ( e.type == SDL_KEYDOWN )
					if ( e.key.keysym.sym == SDLK_p)
						paused = !paused;
				
			}

			if (!paused) {
				for (int i=0; i < 10; i++) {
					drops.push_back(Drop(RandomFloat(0,SCREEN_WIDTH),0,RandomFloat(1,4)));
				}

				for (unsigned int i=0; i < drops.size(); i++) {
					drops[i].update();
				}

				//Erase drops dat are out of the screen.
				vector<Drop>::iterator it = drops.begin();

				while (it != drops.end()) {
					if ((*it).out())
						drops.erase(it);
					else it++;
				}
			}

			//Clean
			SDL_SetRenderDrawColor( background, 255, 255, 255, 255 ); //WHITE
			SDL_RenderClear( background );

			//Draw
			for (unsigned int i=0; i < drops.size(); i++) {
				drops[i].draw(background);
			}
		
			// Render the rect to the screen
    		SDL_RenderPresent(background);

    		cout << drops.size() << endl;

    		SDL_Delay(17);

		}
	}

	//Free resources and close SDL
	close();

	return 0;
}