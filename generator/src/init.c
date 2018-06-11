/*
** EPITECH PROJECT, 2018
** generator
** File description:
** init
*/

#include "dante.h"

static char *init_avaliables_cells(dante_t *dante)
{
	int i = 0;

	dante->avaliable_cells = malloc(sizeof(char) * 4);
	while (i < 4) {
		dante->avaliable_cells[i] = 0;
		i++;
	}
	return (dante->avaliable_cells);
}

static int *init_neighbors_cells(dante_t *dante)
{
	int i = 0;

	dante->neighbors_cells = malloc(sizeof(int) * 4);
	while (i < 4) {
		dante->neighbors_cells[i] = 0;
		i++;
	}
	return (dante->neighbors_cells);
}

static void init_histo(dante_t *dante)
{
	vector_t *position = malloc(sizeof(*position));

	dante->histo = NULL;
	position->coordinate_x = 0;
	position->coordinate_y = 0;
	list_add(&(dante->histo), position);
}

static char **init_maze(size_t m, size_t n)
{
	size_t i = 0;
	char **maze = malloc(sizeof(char *) * m);

	while (i < m) {
		maze[i] = malloc(sizeof(char) * n);
		i++;
	}
	return (maze);
}

dante_t *init_dante(char **av)
{
	dante_t *elem = malloc(sizeof(*elem));

	elem->m = atoi(av[2]);
	elem->n = atoi(av[1]);
	elem->pos_x = 0;
	elem->pos_y = 0;
	elem->maze = init_maze(elem->m, elem->n);
	elem->maze = fill_in_tab(elem);
	elem->neighbors_cells = init_neighbors_cells(elem);
	elem->avaliable_cells = init_avaliables_cells(elem);
	elem->nb_neighbors = 0;
	init_histo(elem);
	return (elem);
}
