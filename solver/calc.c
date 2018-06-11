/*
** EPITECH PROJECT, 2018
** calc.c
** File description:
** calc function
*/

#include "solver.h"

int	calc_end(char *map)
{
	int i = 0;

	while (map[i] != '\0') {
		i += 1;
	}
	i -= 1;
	return (i);
}

int	calc_line(char *map)
{
	int i = 0;

	while (map[i] != '\n') {
		i += 1;
	}
	i += 1;
	return (i);
}
