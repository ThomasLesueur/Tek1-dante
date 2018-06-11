/*
** EPITECH PROJECT, 2018
** generator
** File description:
** manage position
*/

#include "dante.h"

dante_t *get_position(dante_t *dante)
{
	vector_t *position = NULL;

	position = dante->histo->item;
	dante->pos_x = position->coordinate_x;
	dante->pos_y = position->coordinate_y;
	return (dante);
}
