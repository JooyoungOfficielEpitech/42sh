/*
** EPITECH PROJECT, 2018
** how_many_char_star.c
** File description:
** can count nb of the char * in char **
*/

#include "my.h"

int how_many_char_star(char **tab)
{
	int i = 0;

	while (tab[i]) {
		i++;
	}

	return (i);
}
