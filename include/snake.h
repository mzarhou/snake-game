
#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define HEIGHT 200
#define WIDTH 200
#define TARGET_X 5
#define TARGET_Y 5

typedef struct	maillon
{
	int	x;
	int	y;
	struct maillon	*suivant;
}	Snake;

Snake	*mouvement(Snake *S, char direction);
Snake	*inserer_tete(Snake *S, int x, int y);
Snake	*gain(Snake *S, int x, int y);
Snake *makeSnake(int arr[][2], int size);

void drawSnake(SDL_Renderer *renderer, Snake *S, int x, int y);
void clearScreen(SDL_Renderer *renderer);

#endif
