/*
** EPITECH PROJECT, 2018
** algo.c
** File description:
** function for algorithm
*/

#include "solver.h"

void	delete_last_list(path_t *path, int pos, char *map)
{
	while (path->first->pos != pos) {
		map[path->first->pos] = 'P';
		supr_element(path);
	}
}

int	check_path(char *map, path_t *path, path_t *cross, int line)
{
	if (map[path->first->pos + 1] == '*') {
		map[path->first->pos + 1] = 'o';
		add_element(path->first->pos + 1, path);
	}
	else if (map[path->first->pos - line] == '*') {
		map[path->first->pos - line] = 'o';
		add_element(path->first->pos -line, path);
	}
	else if (map[path->first->pos - 1] == '*') {
		map[path->first->pos - 1] = 'o';
		add_element(path->first->pos - 1, path);
	}
	else if (path->first->pos != cross->first->pos) {
		delete_last_list(path, cross->first->pos, map);
		supr_element(cross);
	}
	else
		return (84);
	return (0);
}

int	check_path_2(char *map, path_t *path, int end, int line)
{
	if (path->first->pos < end - (line - 2)
	    && map[path->first->pos + line] == '*') {
		map[path->first->pos + line] = 'o';
		add_element(path->first->pos + line, path);
		return (1);
	}
	return (0);
}

int	algo_path(char *map)
{
	path_t *cross = initialize();
	int	line = calc_line(map);
	int	end = calc_end(map);
	path_t *path = initialize();
	int status = 0;

	map[0] = 'o';
	while (path->first->pos < end) {
		if (check_path_2(map, path, end, line) != 1)
			status =  check_path(map, path, cross, line);
		if (status == 84)
			return (84);
		if (check_crossing(map, path->first->pos, line, end) == 1)
			add_element(path->first->pos, cross);
	}
	free_all(path, cross);
	return (1);
}
