/*
** EPITECH PROJECT, 2018
** define_type.c
** File description:
** define_type.c
*/

#include "list.h"
#include <stdlib.h>

int define_more_type(char *str, int pos)
{
	if (str[pos - 1] == '<') {
		if (str[pos - 2] && str[pos - 2] == '<')
			return (2);
		else
			return (1);
	}
	if (str[pos - 1] == ';')
		return (6);
	return (0);
}

int define_type(char *str, int pos)
{
	if (pos == 0)
		return (0);
	if (str[pos - 1] == '|') {
		if (str[pos - 2] && str[pos - 2] == '|')
			return (8);
		else
			return (5);
	}
	if (str[pos - 1] == '>') {
		if (str[pos - 2] && str[pos - 2] == '>')
			return (4);
		else
			return (3);
	}
	if (str[pos - 1] == '&') {
		return (7);
	}
	return (define_more_type(str, pos));
}
