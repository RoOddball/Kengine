#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

void spherePrimitive(SDL_Renderer* gRenderer, SDL_Point center, int radius){
	
	int circleY = center.y;
	int circleX = center.x;
	int yPosOfCirclePointDown;
	int yPosOfCirclePointUp;
	int xPosOfCirclePoint = circleX - radius;
	
	int circumference_of_circle = floor(2.0*(double)radius*M_PI);
	
	SDL_Point points[circumference_of_circle];
	
	int j = 0;
	int k = circleX + radius;
	int number_of_points;
	
	for(int i=xPosOfCirclePoint; i<=circleX; i++)
	{
		
		yPosOfCirclePointDown = (int)round((2.0*(double)circleY+sqrt(pow((double)circleY*2.0,2.0)-4.0*((pow((double)i-(double)circleX,2.0)+pow((double)circleY,2.0)-pow((double)radius,2.0)))))/2.0);
		points[j*4] = (SDL_Point){i, yPosOfCirclePointDown};
		points[j*4+2] =(SDL_Point){k, yPosOfCirclePointDown};
		
		yPosOfCirclePointUp = (int)round((2.0*(double)circleY-sqrt(pow((double)circleY*2.0,2.0)-4.0*((pow((double)i-(double)circleX,2.0)+pow((double)circleY,2.0)-pow((double)radius,2.0)))))/2.0);
		points[j*4+1] = (SDL_Point){i, yPosOfCirclePointUp}; 
		points[j*4+3] = (SDL_Point){k, yPosOfCirclePointUp};
		
		j++;
		k--;
	}
	
	SDL_RenderDrawLines(gRenderer, points, j*4);
}