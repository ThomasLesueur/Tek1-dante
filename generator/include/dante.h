/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef		_DANTE_H_
#define		_DANTE_H_

#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<math.h>
#include	<time.h>
#include	<string.h>
#include	"list.h"

/*-------MACRO-----*/

#define		VISITED		' '
#define		UNVISITED	'*'
#define		START		'S'
#define		END		'E'
#define		WALL		'X'
#define		BROKEN		'B'
/*------STRUCT-----*/

typedef struct vector_s
{
	int coordinate_x;
        int coordinate_y;
}vector_t;

typedef	struct dante_s
{
        int m;
        int n;
        int pos_x;
        int pos_y;
	char **maze;
	int *neighbors_cells;
	char *avaliable_cells;
        int nb_neighbors;
	list_t *histo;
}dante_t;

/*------PROTO------*/

int	main(int ac, char **av);
void	print_maze_tab(dante_t *dante);
dante_t *init_dante(char **av);
int	verif_state(dante_t *dante);
int	select_next_cell(dante_t *dante);
int	call_func(dante_t *);
char **fill_in_tab(dante_t *);
dante_t *get_position(dante_t *dante);
void	choose_the_next_cell(dante_t *dante);
void	check_neighbors(dante_t *dante);
dante_t *gen_perfect_maze(dante_t *dante);
void	gen_imperfect_maze(dante_t *dante);
void	clear_maze(dante_t *dante);
void	free_all_alloc(dante_t *dante);
void	special_cases(char **);
/*OPT*/
/*-----------------*/

#endif	/*_DANTE_H_*/
