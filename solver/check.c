/*
** EPITECH PROJECT, 2018
** solver
** File description:
** check
*/

#include "solver.h"

static int	check_line(char *map, int i, int line)
{
	int star = 0;

	if (map[i + 1] == '*')
		star += 1;
	if (map[i + line] == '*')
		star += 1;
	if (map[i - 1] == '*')
		star += 1;
	if (star > 1)
		return (1);
	return (0);
}

static int	check_first(char *map, int i, int line)
{
	int star = 0;

	if (map[i + 1] == '*')
		star += 1;
	if (map[i + line] == '*')
		star += 1;
	if (star > 1)
		return (1);
	return (0);
}

int	check_crossing(char *map, int i, int line, int end)
{
	int	star = 0;

	if (i == 0)
		return (check_first(map, i, line));
	else if (i < line - 1)
		return (check_line(map, i, line));
	else {
		if (map[i - 1] == '*')
			star += 1;
		if (map[i - line] == '*')
			star += 1;
		if ( i != end && map[i + 1] == '*')
			star += 1;
		if (i < end - (line - 2) && map[i + line] == '*')
			star += 1;
		if (star > 1)
			return (1);
		return (0);
	}
}
