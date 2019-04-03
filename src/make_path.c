/*
** EPITECH PROJECT, 2018
** make_path.c
** File description:
** path maker
*/

#include "my.h"
#include "sh.h"

char *make_path(char *str, int n)
{
	int i = 0;
	char *ret = malloc(sizeof(char) * my_strlen(str));

	while (str[n]) {
		ret[i] = str[n];
		n++;
		i++;
	}

	ret[i] = '\0';

	return (ret);
}
