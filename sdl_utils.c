#include "include/snake.h"

void drawRect(SDL_Renderer *renderer, int x, int y, int r, int g, int b)
{
	// Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
	SDL_Rect rect;
	rect.x = x * WIDTH / 10;
	rect.y = y * HEIGHT / 10;
	rect.w = WIDTH / 10;
	rect.h = HEIGHT / 10;

	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);

	// Render rect
	SDL_RenderFillRect(renderer, &rect);
}

void drawSnake(SDL_Renderer *renderer, Snake *S, int rand_x, int rand_y)
{
	while (S)
	{
		drawRect(renderer, S->x, S->y, 0, 0, 255);
		S = S->suivant;
	}

	// draw target
	drawRect(renderer, rand_x, rand_y, 0, 255, 0);


	// Render the rect to the screen
	SDL_RenderPresent(renderer);
}

void clearScreen(SDL_Renderer *renderer)
{
	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	// clear
	SDL_RenderClear(renderer);
}
