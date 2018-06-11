/*
** EPITECH PROJECT, 2018
** lists.c
** File description:
** function to add and delete elemnt of list
*/

#include "solver.h"

void	free_all(path_t *path, path_t *cross)
{
	free_lists(path);
	free_lists(cross);
	free(path->first);
	free(cross->first);
	free(path);
	free(cross);
}

void	add_element(int number, path_t *list)
{
	element_t *new = malloc(sizeof(*new));

	if (list == NULL || new == NULL)
		exit (84);
	new->pos = number;
	new->next = list->first;
	list->first = new;
}

void	supr_element(path_t *list)
{
	element_t *elem = list->first;

	list->first = list->first->next;
	free(elem);
}

void	free_lists(path_t *list)
{
	while (list->first->next != NULL) {
		supr_element(list);
	}
}

path_t *initialize(void)
{
	path_t *list = malloc(sizeof(*list));
	element_t *element = malloc(sizeof(*element));

	if (list == NULL || element == NULL)
		exit (84);
	element->pos = 0;
	element->next = NULL;
	list->first = element;
	return (list);
}
