/*
** EPITECH PROJECT, 2018
** my_setenv.c
** File description:
** setenv
*/

#include "my.h"
#include "sh.h"

char *env_maker(char *one, char *two, command *com)
{
	int i = 0, j = 0, k = 0;
	int mal = my_strlen(one) + my_strlen(two) + 2;
	char *ret = malloc(sizeof(char) * (mal + 1));

	com->ret = 0;
	while (one[j]) {
		ret[i] = one[j];
		i++;
		j++;
	}
	ret[i] = '=';
	i++;
	while (two[k]) {
		ret[i] = two[k];
		k++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
int is_eq_there(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] == '=')
			return (1);
		i++;
	}

	return (0);
}
void my_setenv_create(char **tab, command *com)
{
	char *obj;
	int mal;

	com->ret = 0;
	if (how_many_char_star(tab) == 3) {
		mal = my_strlen(tab[1]) + my_strlen(tab[2]) + 2;
		obj = malloc(sizeof(char) * mal);
		obj = env_maker(tab[1], tab[2], com);
		com->env = my_setenv_new(com->env, obj);
	}
	else if (how_many_char_star(tab) == 2)
		com->env = my_setenv_new(com->env, eq(tab[1]));
	else if (how_many_char_star(tab) == 1)
		my_env(com);
	else {
		com->ret = (1);
		my_putstr("setenv: Too many arguments.\n");
	}
}
void my_setenv(char **tab, command *com)
{
	int n, i = 0;

	while (tab[i]) {
		if (is_eq_there(tab[i]) == 1) {
			my_putstr("setenv: Variable name must contain ");
			my_putstr("alphanumeric characters.\n");
			com->ret = -1;
			return;
		}
		i++;
	}
	if (tab[1] && env_find(tab, com->env) == -1)
		my_setenv_create(tab, com);
	else if (!tab[1])
		my_setenv_create(tab, com);
	else {
		n = env_find(tab, com->env);
		com->env[n] = env_maker(tab[1], tab[2], com);
	}
	return;
}
