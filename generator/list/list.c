/*
** EPITECH PROJECT, 2018
** particle.c
** File description:
** particle engine function
*/

#include "dante.h"

void list_add(list_t **v, void *item)
{
	list_t *new = NULL;

	new = malloc(sizeof(*new));
	if (!(new))
		return;
	new->item = item;
	new->next = NULL;
	if (*v == NULL)
		*v = new;
	else {
		new->next = *v;
		*v = new;
	}
}

void list_pop(list_t **v)
{
	list_t *new_head = NULL;

	new_head = (*v)->next;
	free(*v);
	*v = new_head;
}
