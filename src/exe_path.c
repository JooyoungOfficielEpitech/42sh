/*
** EPITECH PROJECT, 2018
** exec_bin.c
** File description:
** can execute binary
*/

#include <string.h>
#include "my.h"
#include "sh.h"

void error_message(char **tab, command *com)
{
	int i = 0;

	if (strcmp(tab[i], "history") == 0)
		return;
	my_putstr(tab[i]);
	com->ret = 1;
	my_putstr(": Command not found.\n");
}
char *slash_name(char *str, char *name)
{
	int i = 0, j = 0, len = my_strlen(str);
	char *ret = malloc(sizeof(char) * (len + my_strlen(name) + 2));

	while (str[j]) {
		ret[i] = str[j];
		i++;
		j++;
	}
	ret[i] = '/';
	i++;
	j = 0;
	while (name[j]) {
		ret[i] = name[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}
int exec_path(char **tab, command *command)
{
	int w, i = 0;
	int pid = fork();
	char **pass = path(command->env);

	if (pid == -1) {
		my_putstr("pid error\n");
		exit(84);
	}
	else if (pid == 0) {
		while (pass[i]) {
			execve(slash_name(pass[i], tab[0]), tab, command->env);
			i++;
		}
		error_message(tab, command);
		command->ret = 1;
		exit(1);
	}
	else
		wait(&w);
	return (WEXITSTATUS(w));
}
