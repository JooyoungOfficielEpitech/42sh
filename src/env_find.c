/*
** EPITECH PROJECT, 2018
** env_find.c
** File description:
** function can find the environnement's argument
*/

#include "my.h"
#include "sh.h"

char *copy_plus(char *str)
{
	int i = 0;
	char *ret = malloc(sizeof(char) * (my_strlen(str) + 2));

	while (str[i]) {
		ret[i] = str[i];
		i++;
	}
	ret[i] = '=';
	ret[i + 1] = '\0';

	return (ret);
}
int env_find(char **tab, char **env)
{
	int i = 0;
	int n = my_strlen(tab[1]);
	char *find = copy_plus(tab[1]);

	while (env[i]) {
		if (my_strncmp(find, env[i], n) == 0)
			return (i);
		i++;
	}
	return (-1);
}
