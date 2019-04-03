/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** aliases_tools
*/

#include <string.h>
#include "my.h"

int is_arg(char *cmd)
{
	int i;

	for (i = 0; cmd[i]; i++) {
		if (cmd[i] == 32)
			return (i);
	}
	return (-1);
}

int send_valid_line(char *tmp, char *cmd)
{
	if (is_arg(cmd) != -1) {
		if (strncmp(tmp, cmd, is_arg(cmd)) == 0)
			return (0);
	}
	else
		if (strcmp(tmp, cmd) == 0)
			return (0);
	return (-1);
}

int do_not_exist(char **tab)
{
	int i;

	for (i = 1; tab[i]; i++) {
		if (strncmp("    alias", tab[i], 9) != 0)
			return (-1);
	}
	return (0);
}

char *my_strdup(char *str)
{
	char *d_str = malloc(sizeof(char) * (my_strlen(str) + 1));

	if (d_str == NULL)
		return (NULL);
	my_strcpy(d_str, str);
	return (d_str);
}
