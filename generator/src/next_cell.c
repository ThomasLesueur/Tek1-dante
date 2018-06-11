/*
** EPITECH PROJECT, 2018
** generator
** File description:
** next cell
*/

#include "dante.h"

static vector_t *set_new_position(dante_t *dante, int rand_nb,
				  vector_t *position)
{
	int i = 0;

	i = rand_nb;
	if (dante->avaliable_cells[i] == 'U') {
		position->coordinate_x -= 2;
		dante->pos_x -= 2;
	}
	else if (dante->avaliable_cells[i] == 'R') {
		position->coordinate_y += 2;
		dante->pos_y += 2;
	}
	else if (dante->avaliable_cells[i] == 'D') {
		position->coordinate_x += 2;
		dante->pos_x += 2;
	}
	else if (dante->avaliable_cells[i] == 'L') {
		position->coordinate_y -= 2;
		dante->pos_y -= 2;
	}
	return (position);
}

static void	wall_breaker(dante_t *dante, int rand_nb)
{
	int i = 0;

	i = rand_nb;
	if (dante->avaliable_cells[i] == 'U') {
		dante->maze[dante->pos_x - 1][dante->pos_y] = BROKEN;
	}
	else if (dante->avaliable_cells[i] == 'R') {
		dante->maze[dante->pos_x][dante->pos_y + 1] = BROKEN;
	}
	else if (dante->avaliable_cells[i] == 'D') {
		dante->maze[dante->pos_x + 1][dante->pos_y] = BROKEN;
	}
	else if (dante->avaliable_cells[i] == 'L') {
		dante->maze[dante->pos_x][dante->pos_y - 1] = BROKEN;
	}
}

void	choose_the_next_cell(dante_t *dante)
{
	int rand_nb = -1;
	vector_t *position = malloc(sizeof(*position));

	position->coordinate_x = dante->pos_x;
	position->coordinate_y = dante->pos_y;
	rand_nb = (rand() % dante->nb_neighbors);
	wall_breaker(dante, rand_nb);
	position = set_new_position(dante, rand_nb, position);
	list_add(&(dante->histo), position);
}
