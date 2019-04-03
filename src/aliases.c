/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** aliases
*/

#include <stdio.h>
#include <string.h>
#include "my.h"

int get_aliase(char **tab, char *cmd)
{
	int i, c, n;
	char *str;
	char *tmp;

	for (i = 1; tab[i]; i++) {
		str = my_strdup(tab[i]);
		str = strtok(str, "=");
		tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
		for (n = 0, c = 10; str[c]; c ++, n ++)
			tmp[n] = str[c];
		tmp[n] = '\0';
		if (send_valid_line(tmp, cmd) == 0)
			return (i);
	}
	return (978);
}

char *get_aliases_cmd(char **tab, char *cmd)
{
	char *tmp = NULL;
	char *new_cmd = NULL;
	int nb;
	int i;
	int n;

	if (do_not_exist(tab) != 0)
		return (NULL);
	nb = get_aliase(tab, cmd);
	if (nb == 978)
		return (NULL);
	tmp = my_strdup(tab[nb]);
	for (i = 0; tmp[i]; i++) {
		if (tmp[i] == 34)
			break;
	}
	new_cmd = malloc(sizeof(char) * (my_strlen(tmp) + 1));
	for (i = i + 1, n = 0; tmp[i]; i ++, n ++)
		new_cmd[n] = tmp[i];
	new_cmd[n] = '\0';
	return (new_cmd);
}

char *add_arg(char *tmp, char *cmd)
{
	int i, n;
	int arg = 0;
	char *s_arg = malloc(sizeof(char) * my_strlen(cmd));

	for (i = 0; cmd[i]; i++) {
		if (cmd[i] == 32) {
			arg = 1;
			break;
		}
	}
	if (arg == 0)
		return (tmp);
	for (n = 0; cmd[i]; i ++, n ++)
		s_arg[n] = cmd[i];
	s_arg[n] = '\0';
	tmp = strcat(tmp, s_arg);
	return (tmp);
}

char *aliases(char *command)
{
	FILE *fp = fopen(".42shrc", "r");
	size_t size = 0;
	char *str = malloc(size * sizeof(char));
	char *tmp = NULL;
	char **tab = malloc(sizeof(char *) * 100);
	int i;

	if (fp == NULL)
		return (command);
	for (i = 0; getline(&str, &size, fp) != -1; i++) {
		str[(my_strlen(str) - 2)] = '\0';
		tab[i] = my_strdup(str);
	}
	tab[i] = NULL;
	fclose(fp);
	tmp = get_aliases_cmd(tab, command);
	if (tmp == NULL)
		return (command);
	tmp = add_arg(tmp, command);
	return (tmp);
}
