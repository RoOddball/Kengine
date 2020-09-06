#include "quadrilateralHeader.h"

void quadrilateralPrimitive(SDL_Renderer* gRenderer, SDL_Point vertexA, SDL_Point vertexB, SDL_Point vertexC, SDL_Point vertexD){
	
	trianglePrimitive(gRenderer, vertexA, vertexB, vertexC);
	trianglePrimitive(gRenderer, vertexB, vertexC, vertexD);
}