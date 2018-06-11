/*
** EPITECH PROJECT, 2018
** solver.h
** File description:
** header files
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct element_s {
	int pos;
	struct element_s *next;
} element_t;

typedef struct liste_s {
	element_t *first;
} path_t;

void	free_all(path_t *, path_t *);
void	free_lists(path_t *);
void	supr_element(path_t *);
path_t	*initialize(void);
void	add_element(int, path_t *);
int	solver(char *);
int	algo_path(char *);
char	*print_p(char *);
int	calc_end(char *);
int	calc_line(char *);
int	check_crossing(char *map, int i, int line, int end);

#endif /*SOLVER_H_*/
