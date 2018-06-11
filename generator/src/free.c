/*
** EPITECH PROJECT, 2018
** generator
** File description:
** free
*/

#include "dante.h"

static void	free_avaliables_cells(dante_t *dante)
{
	free(dante->avaliable_cells);
}

static void	free_neighbors_cells(dante_t *dante)
{
	free(dante->neighbors_cells);
}

static void	free_maze(dante_t *dante)
{
	int i = 0;

	while (i < dante->pos_x) {
		free(dante->maze[i]);
		i++;
	}
	free(dante->maze);
}

void	free_all_alloc(dante_t *dante)
{
	free_avaliables_cells(dante);
	free_neighbors_cells(dante);
	free_maze(dante);
	free(dante);
}
