/*
** EPITECH PROJECT, 2018
** testing for the malloc programm
** File description:
** we need to add a char* in char **
*/

#include "my.h"
#include "sh.h"

char *my_instr(char *str)
{
	char *ret = malloc(sizeof(char) * my_strlen(str) + 1);
	int i = 0;

	while (str[i]) {
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';

	return (ret);
}
char **my_setenv_new(char **env, char *obj)
{
	char **ret = malloc(sizeof(char *) * (how_many_char_star(env) + 2));
	int i = 0;

	while (i != how_many_char_star(env)) {
		ret[i] = malloc(sizeof(char) * my_strlen(env[i]));
		i++;
	}
	ret[i] = malloc(sizeof(char) * 20);
	ret[i + 1] = malloc(sizeof(char) * 3);
	i = 0;
	while (i != how_many_char_star(env)) {
		ret[i] = my_instr(env[i]);
		i++;
	}
	ret[i] = my_instr(obj);
	i++;
	ret[i] = NULL;
	i = 0;
	return (ret);
}
