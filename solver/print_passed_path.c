/*
** EPITECH PROJECT, 2018
** print_*.c
** File description:
** function who print * instead of P
*/

#include "solver.h"

char	*print_p(char *map)
{
	int	i = 0;

	while (map[i] != '\0') {
		if (map[i] == 'P')
			map[i] = '*';
		i += 1;
	}
	return (map);
}
