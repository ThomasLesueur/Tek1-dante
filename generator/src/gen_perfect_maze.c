/*
** EPITECH PROJECT, 2018
** generator
** File description:
** gen perfect maze
*/

#include "dante.h"

static int check_unvisited(dante_t *dante, int i)
{
	int j = 0;

	while (j < dante->n) {
		if (dante->maze[i][j] == UNVISITED) {
			return (0);
		}
		j++;
	}
	return (1);
}

static int	verif_end(dante_t *dante)
{
	int i = 0;

	while (i < dante->m) {
		if (check_unvisited(dante, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

static dante_t	*go_back(dante_t *dante)
{
	vector_t *position;

	list_pop(&(dante->histo));
	position = dante->histo->item;
	dante->pos_x = position->coordinate_x;
	dante->pos_y = position->coordinate_y;
	return (dante);
}

dante_t *gen_perfect_maze(dante_t *dante)
{
	srand(time(NULL));
	while (verif_end(dante) == 0) {
		dante->maze[dante->pos_x][dante->pos_y] = VISITED;
		check_neighbors(dante);
		if (dante->nb_neighbors == 0)
			go_back(dante);
		else {
			choose_the_next_cell(dante);
		}
	}
	if ((dante->m % 2 == 0) && (dante->n % 2 == 0))
		dante->maze[dante->m - 1][dante->n - 2] = BROKEN;
	clear_maze(dante);
	return (dante);
}
