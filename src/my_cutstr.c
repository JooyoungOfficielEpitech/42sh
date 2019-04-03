/*
** EPITECH PROJECT, 2018
** can cut the str
** File description:
** cut
*/

#include <stdlib.h>

char *my_cutstr(char *str, int one, int two)
{
	char *ret = malloc(sizeof(char) * (two - one + 2));
	int in = 0;

	if (!ret)
		return (NULL);
	for (int i = one ; i <= two ; i++) {
		ret[in] = str[i];
		in++;
	}
	ret[in] = '\0';
	return (ret);
}
