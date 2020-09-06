#include "mainHeader.h"
#include <time.h>
SDL_Renderer* gRenderer = NULL;
SDL_Window* gWindow = NULL;

void close(){

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


bool init()
{
	//Initialization flag
	bool success = true;
	
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 480;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "My project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}


int main( int argc, char* args[] )
{
	
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Main loop flag
		bool quit = false;
		
		clock_t start, end;
		double cpu_time_used;
		
		SDL_Event e;
		
		SDL_Point points[30];
		SDL_Point circleCenter = {300, 300};
		
		srand(time(0));
		
  //triangle points
		for(int i=0; i<10; i++)
		{
			points[i*3] = (SDL_Point){rand()%((1+i)*64), rand()%((1+i)*48)};
			points[i*3+1] = (SDL_Point){rand()%((1+i)*64), rand()%((1+i)*48)};
			points[i*3+2] = (SDL_Point){rand()%((1+i)*64), rand()%((1+i)*48)};
		}

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
			}
			
			SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 );
			SDL_RenderClear( gRenderer );
			
			SDL_SetRenderDrawColor(gRenderer, 255, 255, 0, 255);
			
			start = clock();
			

//triangle test

			for(int i=0; i<10; i++)
			{
				SDL_SetRenderDrawColor(gRenderer, (i%8)*25, 100+(i%7)*10, 100+(i%5)*15, 255);
				trianglePrimitive(gRenderer, points[i*3], points[i*3+1], points[i*3+2] );
			}
			end = clock();

			
			//spherePrimitiveByLines(gRenderer, circleCenter, 300);
			//spherePrimitiveByPoints(gRenderer, circleCenter, 300);
			
			end = clock();
			SDL_RenderPresent( gRenderer );
			
			
			cpu_time_used = ((double) (end - start));// CLOCKS_PER_SEC;
			printf("time of the triangle process: %f\n", cpu_time_used);
		}
		
	}

	close();

	return 0;
}