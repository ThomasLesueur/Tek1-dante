/*
** EPITECH PROJECT, 2018
** generator
** File description:
** main
*/

#include "dante.h"

static void print_usage()
{
	write(1, "USAGE :\n\nGENERATOR :\n\t./generator x y [perfect]\n", 50);
	write(1, "\nSOLVER :\n\t./solver maze.txt\n\n", 31);
}

static void check_special_cases(char **av)
{
	if (atoi(av[1]) == 1 || atoi(av[2]) == 1) {
		special_cases(av);
		exit (0);
	}
	if (atoi(av[1]) < 3 && atoi(av[2]) < 3) {
		special_cases(av);
		exit (0);
	}
}

static void check_arguments(char **av)
{
	int i = 0;

	while (av[1][i]) {
		if ((av[1][i] > '9') || (av[1][i] < '0')) {
			write (1, "Error : Bad arguments\n", 23);
			print_usage();
			exit (84);
		}
		i++;
	}
	i = 0;
	while (av[2][i]) {
		if ((av[2][i] > '9') || (av[2][i] < '0')) {
			write (1, "Error : Bad arguments\n", 23);
			print_usage();
			exit (84);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	dante_t *dante = NULL;

	if ((ac < 3) || (ac > 4))
		return (84);
	check_arguments(av);
	check_special_cases(av);
	dante = init_dante(av);
	gen_perfect_maze(dante);
	if ((ac == 4) && (!strcmp(av[3], "perfect"))) {
		print_maze_tab(dante);
		return (0);
	}
	else if (dante->m != 1 && dante->n != 1)
		gen_imperfect_maze(dante);
	clear_maze(dante);
	print_maze_tab(dante);
	free_all_alloc(dante);
	return (0);
}
