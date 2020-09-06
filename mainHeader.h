#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_vulkan.h>

void trianglePrimitive(SDL_Renderer*, SDL_Point, SDL_Point, SDL_Point);
void spherePrimitiveByLines(SDL_Renderer*, SDL_Point, int);
void spherePrimitiveByPoints(SDL_Renderer*, SDL_Point, int, int);
void quadrilateralPrimitive(SDL_Renderer*, SDL_Point, SDL_Point, SDL_Point, SDL_Point);