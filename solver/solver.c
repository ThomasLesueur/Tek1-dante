/*
** EPITECH PROJECT, 2018
** solver.c
** File description:
** function solver
*/

#include "solver.h"

char	*read_file(char *file)
{
	char	*buffer = malloc(sizeof(char) * 10000 * 10000);
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == - 1)
		exit (84);
	buffer[read(fd, buffer, 10000 * 10000)] = '\0';
	close(fd);
	return (buffer);
}

void	display(char *map)
{
	map = print_p(map);
	printf("%s", map);
}

int	solver(char *file)
{
	char *map = read_file(file);

	if (algo_path(map) == 84) {
		printf("%s\n", "no solution found");
		return (84);
	}
	display(map);
	free(map);
	return (1);
}
