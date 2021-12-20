#include "include/snake.h"

int target_x = TARGET_X;
int target_y = TARGET_Y;
int g_direction = 'S';

int	snakeHasPosition(Snake *S, int x, int y)
{
	while (S)
	{
		if (S->x == x && S->y == y)
			return (1);
		S = S->suivant;
	}
	return (0);
}

void updateTargetPosition(Snake *S)
{
	int	x;
	int	y;

	srand(time(0));
	do
	{
		x = rand() % 10;
		y = rand() % 10;
	} while (snakeHasPosition(S, x, y));
	target_x = x;
	target_y = y;
}

Snake *updateScreen(Snake *S, SDL_Renderer *renderer, char direction)
{
	S = mouvement(S, direction);
	if (S) {
		S = gain(S, target_x, target_y);
		if (target_x == S->x && target_y == S->y) {
			updateTargetPosition(S);
		}
		clearScreen(renderer);
		drawSnake(renderer, S, target_x, target_y);
	}
	return S;
}

Snake	*initialiser_Snake()
{
	Snake *S = 0;
	return inserer_tete(S, 0, 2);
}

int main()
{
	SDL_Window *window = NULL;
	window = SDL_CreateWindow(
		"SNAKE", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIDTH,
		HEIGHT,
		SDL_WINDOW_SHOWN);

	// Setup renderer
	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	clearScreen(renderer);

	Snake *S = initialiser_Snake();
	drawSnake(renderer, S, target_x, target_y);
	clearScreen(renderer);

	//
	SDL_Event e;
	int quit = 0;
	while (!quit && S)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = 1;
			else if (e.type == SDL_KEYDOWN)
				switch (e.key.keysym.sym)
				{
				case SDLK_RIGHT:
					g_direction = 'E';
					break;
				case SDLK_LEFT:
					g_direction = 'O';
					break;
				case SDLK_UP:
					g_direction = 'N';
					break;
				case SDLK_DOWN:
					g_direction = 'S';
					break;
				default:
					break;
				}
		}
		S = updateScreen(S, renderer, g_direction);
		SDL_Delay(150);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
