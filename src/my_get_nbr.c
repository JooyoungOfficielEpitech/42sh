/*
** EPITECH PROJECT, 2017
** my_get_nbr.c
** File description:
** Write a function that returns a number, sent to the function as a string.
*/

#include "my.h"

int my_get_nbr(char const *str)
{
	int i = 0;
	int nb = 0;
	int negative = 1;

	if (str[i] == '-') {
		negative = (-1);
		i++;
	}
	while (str[i] != '\0') {
		nb = nb + str[i] - 48;
		if (str[i + 1] != '\0') {
			nb = nb * 10;
		}
		i++;
	}
	return (nb * negative);
}
