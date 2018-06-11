/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/

#include "solver.h"


int	main(int ac, char **av)
{
	if (ac != 2)
		return (84);
	solver(av[1]);
	return (0);
}
