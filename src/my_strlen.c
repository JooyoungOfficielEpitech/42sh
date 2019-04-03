/*
** EPITECH PROJECT, 2018
** my
** File description:
** my
*/

#include "my.h"

int my_strlen(char *str)
{
	int i = 0;

	while (str[i]) {
		i++;
	}

	return (i);
}
