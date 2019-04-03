/*
** EPITECH PROJECT, 2018
** count_space.c
** File description:
** counting the nb of the space
*/

#include "my.h"

int how_many_are_we(char *str, char a)
{
	int space = 0;
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == a)
			space++;
		i++;
	}

	return (space);
}
