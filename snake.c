#include "include/snake.h"

int	queue_x = -1;
int	queue_y = -1;

int	taille(Snake *S)
{
	int	count;

	count = 0;
	while (S && S->suivant)
	{
		count++;
		S = S->suivant;
	}
	return (count);
}

void	detruite(Snake **S)
{
	Snake	*suivant;

	while (S != NULL && *S != NULL)
	{
		suivant = (*S)->suivant;
		free(*S);
		(*S) = suivant;
	}
}

int	mordre(Snake *S)
{
	Snake	*tete;

	if (S->x > 9 || S->x < 0 || S->y > 9 || S->y < 0)
		return (1);
	tete = S;
	S = S->suivant;
	while (S)
	{
		if (S->x == tete->x && S->y == tete->y)
			return (1);
		S = S->suivant;
	}
	return (0);
}

Snake	*inserer_tete(Snake *S, int x, int y)
{
	Snake	*new;

	new = (Snake *)malloc(sizeof(Snake));
	new->x = x;
	new->y = y;
	new->suivant = S;
	return (new);
}

Snake	*inserer_fin(Snake *S, int x, int y)
{
	Snake	*new;
	Snake	*temp;

	new = (Snake *)malloc(sizeof(Snake));
	new->x = x;
	new->y = y;
	new->suivant = NULL;

	if (S == NULL)
		return new;
	temp = S;
	while (temp->suivant)
		temp = temp->suivant;
	temp->suivant = new;
	return (S);
}

Snake	*supprimer_debut(Snake *S)
{
	Snake	*tete = S;
	if (S == NULL)
		return (NULL);
	S = S->suivant;
	free(tete);
	return (S);
}

Snake	*supprimer_queue(Snake *S)
{
	Snake	*tete;

	tete = S;
	if (S == NULL)
		return NULL;
	while (S->suivant && S->suivant->suivant)
	{
		S = S->suivant;
	}
	queue_x = S->suivant->x;
	queue_y = S->suivant->y;
	free(S->suivant);
	S->suivant = NULL;
	return (tete);
}

Snake	*mouvement(Snake *S, char direction)
{
	int	x;
	int	y;

	if (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'O')
		return (S);

	if (direction == 'N')
	{
		x = S->x;
		y = S->y - 1;
	}
	if (direction == 'S')
	{
		x = S->x;
		y = S->y + 1;
	}
	if (direction == 'E')
	{
		x = S->x + 1;
		y = S->y;
	}
	if (direction == 'O')
	{
		x = S->x - 1;
		y = S->y;
	}
	S = inserer_tete(S, x, y);
	if (mordre(S))
	{
		printf("Perdu\n");
		detruite(&S);
	}
	else
		S = supprimer_queue(S);
	return (S);
}

Snake	*gain(Snake *S, int x, int y)
{
	if (S->x == x && S->y == y)
		return inserer_fin(S, queue_x, queue_y);
	return S;
}
