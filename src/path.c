/*
** EPITECH PROJECT, 2018
** path
** File description:
** path
*/

#include "my.h"
#include "sh.h"

int where_path(char **env)
{
	int i = 0;

	while (my_strncmp(env[i], "PATH=", 4) != 0) {
		i++;
	}

	return (i);
}
char **path(char **env)
{
	int i = where_path(env), j = 0, m = 5, in = 0, move = 0;
	char **re = malloc(sizeof(char *) * (how_many_are_we(env[i], ':') + 2));

	while (j != how_many_are_we(env[i], ':') + 1) {
		re[j] = malloc(sizeof(char) * my_strlen(env[i]) + 1);
		j++;
	}
	while (env[i][m] && in != how_many_are_we(env[i], ':')) {
		while (env[i][m] != ':') {
			re[in][move] = env[i][m];
			move++;
			m++;
		}
		re[in][move] = '\0';
		move = 0;
		in++;
		m++;
	}
	re[in] = NULL;
	return (re);
}
