/*
** EPITECH PROJECT, 2018
** generator
** File description:
** special cases
*/

#include "dante.h"

static void	square_2x2()
{
	int nb = 0;

	srand(time(NULL));
	nb = rand();

	if (nb % 2 == 1) {
		write(1, "*X\n**\n", 6);
	}
	else
		write(1, "**\nX*\n", 6);
}

static void	one_column(char **av)
{
	int i = 0;

	while (i < atoi(av[1])) {
		write(1, "*", 1);
		i++;
	}
	write(1, "\n", 1);
}

static void	one_line(char **av)
{
	int i = 0;

	while (i < atoi(av[2])) {
		write(1, "*\n", 2);
		i++;
	}
}

void	special_cases(char **av)
{
	if (atoi(av[1]) == 0 || atoi(av[2]) == 0)
		exit (84);
	else if (atoi(av[1]) == 1 && atoi(av[2]) == 1)
		write(1, "*\n", 2);
	else if (atoi(av[1]) == 1 && atoi(av[2]) != 1)
		one_line(av);
	else if (atoi(av[1]) != 1 && atoi(av[2]) == 1)
		one_column(av);
	else if (atoi(av[1]) == 2 && atoi(av[2]) == 2)
		square_2x2();
}
