/*
** EPITECH PROJECT, 2018
** generator
** File description:
** gen imperfect maze
*/

#include "dante.h"

static int	random_breaker(dante_t *dante, int i, int count)
{
	int j = 0;
	int nb = 0;

	while (j < dante->n) {
		nb = rand() % 4;
		if (dante->maze[i][j] == WALL
			&& (i != 0 && j != 0
			&& j != dante->n - 1 && i != dante->m - 1)
			&& nb == 0) {
			dante->maze[i][j] = BROKEN;
			count++;
		}
		j++;
	}
	return (count);
}

void	gen_imperfect_maze(dante_t *dante)
{
	int i = 0;
	int count = 0;

	while (i < dante->m - 1) {
		if (dante->n < 3 || dante->m < 3)
			break;
		count = random_breaker(dante, i, count);
		i++;
		if ((i == dante->m - 1) && (count == 0))
			i = 0;
	}
}
