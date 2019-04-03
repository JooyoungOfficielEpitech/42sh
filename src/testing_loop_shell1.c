/*
** EPITECH PROJECT, 2018
** testing list shell
** File description:
** tester
*/

#include "my.h"
#include "sh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int file_descriptor_opener(char *name, int type)
{
	int file;

	if (type == 1) {
		file = open(name, O_CREAT |		\
			    O_RDWR, S_IRUSR | S_IWUSR |
			    S_IRGRP | S_IWGRP | S_IROTH);
	}
	else {
		file = open(name, O_CREAT | O_APPEND |
			    O_RDWR, S_IRUSR | S_IWUSR |
			    S_IRGRP | S_IWGRP | S_IROTH);
	}
	if (file == -1)
		exit(84);
	return (file);
}
void write_execution_test(list_t *head, command *com, int type)
{
	int pipefd[2];
	int pid;
	int file = file_descriptor_opener(head->next->commands[0], type);
	char *buf = malloc(sizeof(char));

	if (!buf)
		exit(84);
	pipe(pipefd);
	pid = fork();
	if (pid == 0) {
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		while (read(pipefd[0], buf, 1) != 0)
			write(file, buf, 1);
	}
	else {
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		exec_bin(head->commands, com->env, com);
	}
	close(file);
}

void multiple_execution(list_t *head, command *com, int type)
{
	com->ret = exec_bin(head->commands, com->env, com);
	if (head->next == NULL)
		return;
	if (type == 6)
		loop_shell(head->next, com, head->next->type);
	if (type == 7) {
		if (com->ret == 0)
			loop_shell(head->next, com, head->next->type);
		else
			head->next = NULL;
	}
	if (type == 8) {
		if (com->ret != 0)
			loop_shell(head->next, com, head->next->type);
		else
			head->next = NULL;
	}
}

void loop_shell(list_t *head, command *com, int type)
{
	if (type == 3)
		write_execution_test(head, com, 1);
	if (type == 4)
		write_execution_test(head, com, 2);
	if (type == 1)
		read_execution(head, com, 3);
	if (type == 2)
		read_execution(head, com, 4);
	if (type == 5)
		pipe_execution_double(head, com);
	if (type == 6)
		multiple_execution(head, com, 6);
	if (type == 7)
		multiple_execution(head, com, 7);
	if (type == 8)
		multiple_execution(head, com, 8);
}

void pipe_execution_double(list_t *head, command *com)
{
	int pipefd[2];
	int pid;

	pipe(pipefd);
	pid = fork();
	if (pid == 0) {
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		if (head->next->next == NULL)
			exec_bin(head->next->commands, com->env, com);
		else
			loop_shell(head->next, com, head->next->next->type);
	}
	else {
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		exec_bin(head->commands, com->env, com);
	}
}
