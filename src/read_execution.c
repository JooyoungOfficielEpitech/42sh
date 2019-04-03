/*
** EPITECH PROJECT, 2018
** read_execution.c
** File description:
** read_execution.c
*/

#include "my.h"
#include "sh.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char *input_maker(int file)
{
	char *all = malloc(sizeof(0));
	char *input;

	input = get_next_line(file);
	while (input != NULL) {
		all = my_concat(all, input);
		input = get_next_line(file);
	}
	all = end_of_str(all);
	return (all);
}

char *input_maker_for_usr(char *token)
{
	char *all = malloc(sizeof(0));;
	char *input;

	my_putstr("? ");
	input = get_next_line(0);
	while (strcmp(input, token) != 0) {
		all = my_concat(all, input);
		my_putstr("? ");
		input = get_next_line(0);
	}
	all = end_of_str(all);
	return (all);
}

int read_input_usr(list_t *head, command *com)
{
	int pipefd[2];
	int ret = 0;
	int pid;
	char *all;

	all = input_maker_for_usr(head->next->commands[0]);
	pipe(pipefd);
	pid = fork();
	if (pid == 0) {
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		ret = exec_bin(head->commands, com->env, com);
	}
	else {
		close(pipefd[0]);
		write(pipefd[1], all, strlen(all));
	}
	return (ret);
}

int read_file_lines(list_t *head, command *com)
{
	int pipefd[2];
	int ret = 0;
	int pid;
	char *all;
	int file = open(head->next->commands[0], O_RDONLY);

	all = input_maker(file);
	pipe(pipefd);
	pid = fork();
	if (pid == 0) {
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		ret = exec_bin(head->commands, com->env, com);
	}
	else {
		close(pipefd[0]);
		write(pipefd[1], all, strlen(all));
	}
	return (ret);
}

void read_execution(list_t *head, command *com, int type)
{
	if (type == 3)
		com->ret = read_file_lines(head, com);
	else
		com->ret = read_input_usr(head, com);
	prompt();
}
