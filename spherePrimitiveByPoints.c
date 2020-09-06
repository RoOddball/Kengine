#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

void spherePrimitiveByPoints(SDL_Renderer* gRenderer, SDL_Point center, int radius){
	
	//int count_between_Ys = 0;
	int circleY = center.y;
	int circleX = center.x;
	int yPosOfCirclePointDown;
	int yPosOfCirclePointUp;
	int xPosOfCirclePoint = circleX - radius;
	
	int area_of_circle = floor(2.0*pow((double)radius,2.0)*M_PI);
	
	int number_of_inner_circles = radius;
	int j;
	int k;
	int rightX;
	int leftX;
	int count_of_points = 0;
	
	SDL_Point* points = (SDL_Point*)(malloc(sizeof(SDL_Point)*area_of_circle));
	//SDL_Point points[area_of_circle];
	
	while(radius>0)
	{
		//j = 0;
		rightX  = circleX + radius;
		leftX = circleX - radius;
		k = rightX;
		int previousY = circleY ;
		
		for(int i=leftX; i<=circleX; i++)
		{
			
			yPosOfCirclePointDown = (int)round((2.0*(double)circleY+sqrt(pow((double)circleY*2.0,2.0)-4.0*((pow((double)i-(double)circleX,2.0)+pow((double)circleY,2.0)-pow((double)radius,2.0)))))/2.0);
			points[j*4] = (SDL_Point){i, yPosOfCirclePointDown};
			points[j*4+1] =(SDL_Point){k, yPosOfCirclePointDown};
			
			yPosOfCirclePointUp = (int)round((2.0*(double)circleY-sqrt(pow((double)circleY*2.0,2.0)-4.0*((pow((double)i-(double)circleX,2.0)+pow((double)circleY,2.0)-pow((double)radius,2.0)))))/2.0);
			points[j*4+2] = (SDL_Point){i, yPosOfCirclePointUp}; 
			points[j*4+3] = (SDL_Point){k, yPosOfCirclePointUp};
			
			
			//SDL_RenderDrawPoint(gRenderer, i, yPosOfCirclePointDown);
			//SDL_RenderDrawPoint(gRenderer, k, yPosOfCirclePointDown);
			//SDL_RenderDrawPoint(gRenderer, i, yPosOfCirclePointUp);
			//SDL_RenderDrawPoint(gRenderer, k, yPosOfCirclePointUp);
			
			
			j++;
			count_of_points++;
			
			if((previousY-yPosOfCirclePointUp)>0.0)
				for(int l=previousY-yPosOfCirclePointUp; l>0; l--)
				{
					
					//printf("inthere l: %d\n",l);
					
					points[j*4] = (SDL_Point){i, yPosOfCirclePointDown-l};
					points[j*4+1] =(SDL_Point){k, yPosOfCirclePointDown-l};
					points[j*4+2] = (SDL_Point){i, yPosOfCirclePointUp+l}; 
					points[j*4+3] = (SDL_Point){k, yPosOfCirclePointUp+l};
					//SDL_RenderDrawPoint(gRenderer, i, yPosOfCirclePointDown-l);
					//SDL_RenderDrawPoint(gRenderer, k, yPosOfCirclePointDown-l);
					//SDL_RenderDrawPoint(gRenderer, i, yPosOfCirclePointUp+l);
					//SDL_RenderDrawPoint(gRenderer, k, yPosOfCirclePointUp+l);
					//count_of_points = count_of_points+4;
					j++;
					count_of_points++;
				}
			
			previousY = yPosOfCirclePointUp;
			
			k--;
		}
		radius--;
	}
	//printf("size of array: %d\n",sizeof(points)/sizeof(SDL_Point));
	
	SDL_RenderDrawPoints(gRenderer,points,count_of_points*4);
	
	
	free(points);
	points = NULL;
	
	//SDL_RenderDrawPoints(gRenderer,points,number_of_points);
		
}