/*
** EPITECH PROJECT, 2018
** my_unsetenv.c
** File description:
** unsetenv main
*/

#include "my.h"
#include "sh.h"

char *eq(char *str)
{
	char *ret = malloc(sizeof(char) * my_strlen(str) + 2);
	int i = 0;

	while (str[i]) {
		ret[i] = str[i];
		i++;
	}
	ret[i] = '=';
	ret[i + 1] = '\0';

	return (ret);
}
char **unset_env(char *str, char **env)
{
	char **ret = malloc(sizeof(char *) * (how_many_char_star(env) + 1));
	int i = 0, j = 0, l = 0, len = my_strlen(str);

	while (l != how_many_char_star(env)) {
		ret[l] = malloc(sizeof(char) * my_strlen(env[l]));
		l++;
	}
	ret[l] = malloc(sizeof(char) * 3);
	while (env[j] && i != how_many_char_star(env)) {
		if (env[j + 1] && my_strncmp(env[j], eq(str), len) == 0)
			j++;
		ret[i] = my_instr(env[j]);
		i++;
		j++;
	}
	if (i == j && my_strncmp(eq(str), env[j - 1], my_strlen(str)) == 0)
		i--;
	ret[i] = NULL;
	return (ret);
}
void my_unsetenv(char **tab, command *com)
{
	int rep = 0;
	int nb = how_many_char_star(tab);

	if (nb == 1) {
		com->ret = 1;
		my_putstr("unsetenv: Too few arguments.\n");
	}
	else {
		while (rep != (nb - 1)) {
			com->env = unset_env(tab[rep + 1], com->env);
			rep++;
			com->ret = 0;
		}
	}
}
