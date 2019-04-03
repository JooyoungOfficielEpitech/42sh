/*
** EPITECH PROJECT, 2018
** list.h
** File description:
** lsit.h
*/

#ifndef LIST$_H
#define LIST_H

typedef struct list_s {
	int type;
	char **commands;
	struct list_s *next;
	struct list_s *before;
} list_t;

void add_node(list_t *, int);

#endif
