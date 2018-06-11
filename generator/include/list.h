/*
** EPITECH PROJECT, 2018
** list.h
** File description:
** header files
*/

#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct vector_s vector_t;

typedef struct list_s {
	void *item;
	struct list_s *next;
}list_t;

void list_add(list_t **, void *);
void list_pop(list_t **);

#endif /* LIST_H_ */
