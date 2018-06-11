/*
** EPITECH PROJECT, 2018
** generator
** File description:
** check
*/

#include "dante.h"

static int set_avaliable_cell_tab_2(dante_t *dante, int i)
{
	if ((dante->neighbors_cells[3] != 0) &&
	    (dante->maze[dante->pos_x][dante->pos_y - 2] == UNVISITED) ) {
		dante->avaliable_cells[i] = 'L';
		i++;
	}
	return (i);
}

static void set_avaliable_cell_tab(dante_t *dante)
{
	int i = 0;

	if ((dante->neighbors_cells[0] != 0) &&
	(dante->maze[dante->pos_x - 2][dante->pos_y] == UNVISITED) ) {
		dante->avaliable_cells[i] = 'U';
		i++;
	}
	if ((dante->neighbors_cells[1] != 0) &&
		 (dante->maze[dante->pos_x][dante->pos_y + 2] == UNVISITED) ) {
		dante->avaliable_cells[i] = 'R';
		i++;
	}
	if ((dante->neighbors_cells[2] != 0) &&
		 (dante->maze[dante->pos_x + 2][dante->pos_y] == UNVISITED) ) {
		dante->avaliable_cells[i] = 'D';
		i++;
	}
	i = set_avaliable_cell_tab_2(dante, i);
	dante->nb_neighbors = i;
}
void	check_neighbors_2(dante_t *dante)
{
	if (dante->pos_y - 2 < 0) {
		dante->neighbors_cells[3] = 0;
	}
	else
		dante->neighbors_cells[3] = 1;
}

void	check_neighbors(dante_t *dante)
{
	if (dante->pos_x - 2 < 0) {
		dante->neighbors_cells[0] = 0;
	}
	else
		dante->neighbors_cells[0] = 1;
	if (dante->pos_y + 2 > dante->n - 1) {
		dante->neighbors_cells[1] = 0;
	}
	else {
		dante->neighbors_cells[1] = 1;
	}
	if (dante->pos_x + 2 > dante->m - 1) {
		dante->neighbors_cells[2] = 0;
	}
	else
		dante->neighbors_cells[2] = 1;
	check_neighbors_2(dante);
	set_avaliable_cell_tab(dante);
}
