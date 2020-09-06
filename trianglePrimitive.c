#include <SDL2/SDL.h>

void trianglePrimitive(SDL_Renderer* gRenderer, SDL_Point point1, SDL_Point point2, SDL_Point point3)
{
	
	 SDL_Point vertex1 = {point1.x, point1.y};
	 SDL_Point vertex2 = {point2.x, point2.y};
	 SDL_Point vertex3 = {point3.x, point3.y};
	
	double constB;
	double constD;
	double constF;
	
	if(vertex1.x != vertex2.x)
		constB = ((double)vertex1.y - (double)vertex2.y) / ((double)vertex1.x - (double)vertex2.x);
	else
		constB = (double)vertex1.y - (double)vertex2.y;
	
	double constA = (double)vertex1.y - constB * (double)vertex1.x;
	int constX = vertex2.y - vertex1.y;
	
	if(vertex1.x != vertex3.x)
		constD = ((double)vertex1.y - (double)vertex3.y) / ((double)vertex1.x - (double)vertex3.x);
	else
		constD = (double)vertex1.y - (double)vertex3.y;
	
	double constC = (double)vertex1.y - constD * (double)vertex1.x;
	int constY = vertex3.y - vertex1.y;
	
	if(vertex2.x != vertex3.x)
		constF = ((double)vertex2.y - (double)vertex3.y) / ((double)vertex2.x - (double)vertex3.x);
	else
		constF = (double)vertex2.y - (double)vertex3.y;
	
	double constE = (double)vertex2.y - constF * (double)vertex2.x;
	
	int highestY;
	int secondHighestY;
	int thirdY;
	int length_on_Y_axis;
	double relativeConstA;
	double relativeConstB;
	double relativeConstC;
	double relativeConstD;
	double relativeConstE;
	double relativeConstF;
			
	if(vertex1.y < vertex2.y && vertex1.y < vertex3.y)
		if(vertex2.y > vertex3.y)
		{
			highestY = vertex1.y;
			secondHighestY = vertex3.y;
			thirdY = vertex2.y;
			
			relativeConstA = constA;
			relativeConstB = constB;
			relativeConstC = constC;
			relativeConstD = constD;
			relativeConstE = constE;
			relativeConstF = constF;
		}
		else
		{
			highestY = vertex1.y;
			secondHighestY = vertex2.y;
			thirdY = vertex3.y;
			
			relativeConstA = constC;
			relativeConstB = constD;
			relativeConstC = constA;
			relativeConstD = constB;
			relativeConstE = constE;
			relativeConstF = constF;
		}
	else if(vertex2.y < vertex1.y && vertex2.y < vertex3.y)
		if(vertex1.y < vertex3.y)
		{
			highestY = vertex2.y;
			secondHighestY = vertex1.y;
			thirdY = vertex3.y;
			
			relativeConstA = constE;
			relativeConstB = constF;
			relativeConstC = constA;
			relativeConstD = constB;
			relativeConstE = constC;
			relativeConstF = constD;
		}
		else
		{
			highestY = vertex2.y;
			secondHighestY = vertex3.y;
			thirdY = vertex1.y;
			
			relativeConstA = constA;
			relativeConstB = constB;
			relativeConstC = constE;
			relativeConstD = constF;
			relativeConstE = constC;
			relativeConstF = constD;
		}
	else
		if(vertex1.y < vertex2.y)
		{
			highestY = vertex3.y;
			secondHighestY = vertex1.y;
			thirdY = vertex2.y;
			
			relativeConstA = constE;
			relativeConstB = constF;
			relativeConstC = constC;
			relativeConstD = constD;
			relativeConstE = constA;
			relativeConstF = constB;
		}
		else
		{
			highestY = vertex3.y;
			secondHighestY = vertex2.y;
			thirdY = vertex1.y;
			
			relativeConstA = constC;
			relativeConstB = constD;
			relativeConstC = constE;
			relativeConstD = constF;
			relativeConstE = constA;
			relativeConstF = constB;
		}
	
	length_on_Y_axis = thirdY - highestY;
	int size_of_points = length_on_Y_axis * 2;
	
	//SDL_Point points[size_of_points];
	SDL_Point* points = (SDL_Point*)malloc(sizeof(SDL_Point)*size_of_points);
	
	int j = 0;
	int k = 1;
	
	for(int i=highestY; i<secondHighestY; i++ )
	{
		
		if(k>0)
		{
			points[j*2] = (SDL_Point){(int)ceil(((double)i-relativeConstA)/relativeConstB), i};
			points[j*2+1] = (SDL_Point){(int)ceil(((double)i-relativeConstC)/relativeConstD), i};
			
			
		}
		else
		{
			points[j*2] = (SDL_Point){(int)ceil(((double)i-relativeConstC)/relativeConstD), i};
			points[j*2+1] = (SDL_Point){(int)ceil(((double)i-relativeConstA)/relativeConstB), i};
		}
		
		j++;
		k = k * (-1);
	}
	
	int l = secondHighestY - highestY;
	int m = 1;
	
	for(int i=secondHighestY; i<thirdY; i++)
	{
		
		if(m>0)
		{
			points[l*2] = (SDL_Point){(int)ceil(((double)i-relativeConstA)/relativeConstB), i};
			points[l*2+1] = (SDL_Point){(int)ceil(((double)i-relativeConstE)/relativeConstF), i};
			//printf("---%d x: %d, y: %d \n", l, (int)ceil(((double)i-relativeConstA)/relativeConstB), i);
		}
		else
		{
			points[l*2] = (SDL_Point){(int)ceil(((double)i-relativeConstE)/relativeConstF), i};
			points[l*2+1] = (SDL_Point){(int)ceil(((double)i-relativeConstA)/relativeConstB), i};
			//printf("---%d x: %d, y: %d \n", l, (int)ceil(((double)i-relativeConstA)/relativeConstB), i);
		}
		l = l + 1;
		m = m * (-1);
	}
	
	SDL_RenderDrawLines(gRenderer, points, size_of_points);
	
	free(points);
	points = NULL;
}