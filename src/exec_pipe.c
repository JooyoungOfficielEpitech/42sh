/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** exec_pipe
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "sh.h"
#include "my.h"

void go_pipe(list_t *head, command *com)
{
	exec_bin(head->commands, com->env, com);
}

void pipe_execution(char **one, char **two, char **env, command *com)
{
	int pipefd[2];
	int pid;
	int pid2;
	int w;

	pipe(pipefd);
	pid = fork();
	if (pid == 0) {
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		exec_bin(two, env, com);
	}
	else {
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		exec_bin(one, env, com);
	}
	close(pipefd[0]);
	close(pipefd[1]);
}

static char *add_char(char *str, char a)
{
	char *ret = malloc(sizeof(char) * (my_strlen(str) + 2));
	int i = 0;

	for (; i != my_strlen(str); i++)
		ret[i] = str[i];
	ret[i] = a;
	ret[i + 1] = '\0';
	return (ret);
}

static char *remove_the_space(char *str)
{
	char *ret = malloc(sizeof(char) * (my_strlen(str) + 1));
	int i = 0;
	int j = 0;

	while (i != my_strlen(str)) {
		if (j == 0 && str[j] == ' ')
			j++;
		if (str[j] == ' ' && str[j + 1] && str[j + 1] == ' ')
			j++;
		if (str[j] == ' ' && str[j + 1] == '\0')
			j++;
		ret[i] = str[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

int pipe_exec(char *av, command *com)
{
	return (0);
}
