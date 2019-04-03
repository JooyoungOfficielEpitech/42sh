/*
** EPITECH PROJECT, 2018
** compare
** File description:
** compare
*/

#include "my.h"

int my_strcmp(char *one, char *two)
{
	int i = 0;

	if (my_strlen(one) != my_strlen(two))
		return (0);
	while (one[i] && two[i]) {
		if (one[i] == two[i])
			i++;
		else
			return (0);
	}
	return (1);
}
