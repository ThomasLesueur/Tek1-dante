/*
** EPITECH PROJECT, 2018
** generator
** File description:
** maze functions
*/

#include	"dante.h"

void	print_maze_tab(dante_t *dante)
{
	int i = 0;
	int j = 0;

	while (i < dante->m) {
		while (j < dante->n) {
			printf("%c", dante->maze[i][j]);
			j++;
		}
		if (i != dante->m - 1)
			printf("\n");
		j = 0;
		i++;
	}
}

static void fill_in_cell(dante_t *dante, int i)
{
	int j = 0;

	while (j < dante->n) {
		if (j % 2 == 0 && i % 2 == 0) {
			dante->maze[i][j] = UNVISITED;
		}
		else
			dante->maze[i][j] = WALL;
		j++;
	}
}

char **fill_in_tab(dante_t *dante)
{
	int i = 0;

	while (i < dante->m) {
		fill_in_cell(dante, i);
		i++;
	}
	dante->maze[dante->m - 1][dante->n - 1] = END;
	return (dante->maze);
}

static void clear_cell(dante_t *dante, int i)
{
	int j = 0;

	while (j < dante->n) {
		if ((dante->maze[i][j] == VISITED) ||
		    (dante->maze[i][j] == END) ||
		    (dante->maze[i][j] == START))
			dante->maze[i][j] = '*';
		if (dante->maze[i][j] == BROKEN)
			dante->maze[i][j] = '*';
		if (dante->maze[i][j] == UNVISITED)
			dante->maze[i][j] = '*';
		j++;
	}
}

void clear_maze(dante_t *dante)
{
	int i = 0;

	while (i < dante->m) {
		clear_cell(dante, i);
		i++;
	}
	if ((dante->m % 2 == 1) && (dante->n % 2 == 1))
		dante->maze[dante->m - 1][dante->n - 2] = '*';
}
