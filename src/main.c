/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for the project minishell
*/

#include "sh.h"
#include "my.h"
#include "gnl.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <curses.h>
#include <string.h>
#include <stdio.h>

void set_com(command *com, char **env)
{
	char *tab[] = { "unsetenv", "OLDPWD", NULL };

	com->ret = 0;
	com->env = env;
	com->i = 0;
	my_unsetenv(tab, com);
}

static int binary_execution(list_t *head, command *com)
{
	int ret;
	int pid;

	pid = fork();
	if (pid == 0) {
		if (head->next == NULL)
			com->ret = exec_bin(head->commands, com->env, com);
		else
			loop_shell(head, com, head->next->type);
		exit(com->ret);
	}
	else
		wait(&ret);
	return (WEXITSTATUS(ret));
}

void minishell(list_t *head, command *com)
{
	if (my_strcmp(head->commands[0], "cd") == 1)
		my_cd(head->commands, com);
	else if (my_strcmp(head->commands[0], "env") == 1)
		my_env(com);
	else if (my_strcmp(head->commands[0], "exit") == 1)
		my_exit(head->commands);
	else if (my_strcmp(head->commands[0], "setenv") == 1)
		my_setenv(head->commands, com);
	else if (my_strcmp(head->commands[0], "unsetenv") == 1)
		my_unsetenv(head->commands, com);
	else
		com->ret = binary_execution(head, com);
}

void prompt(void)
{
	char buff[100];
	char *curent_dir = NULL;
	int nb_slash = 0;

	getcwd(buff, 100);
	curent_dir = strdup(buff);
	for (int i = 0; curent_dir[i]; i++) {
		if (curent_dir[i] == '/') {
			nb_slash++;
		}
	}
	curent_dir = strtok(curent_dir, "/");
	while (nb_slash != 1) {
		curent_dir = strtok(NULL, "/");
		nb_slash--;
	}
	my_putstr("[42SH - ");
	my_putstr(curent_dir);
	my_putstr("]$ ");
}

int main(int ac, char **av, char **env)
{
	char *cmd;
	struct command *com = malloc(sizeof(command));
	list_t *head = malloc(sizeof(list_t));

	set_and_err(ac, av, com, env);
	while (com->i == 0) {
		prompt();
		cmd = get_next_line(0);
		if (cmd == NULL) {
			exit_and_rmv();
			return (com->ret);
		}
		cmd = aliases(cmd);
		history(cmd);
		if (cmd[0] != '\0') {
			com->past = cmd;
			head = parsing_commands(rm_spacer(cmd));
			minishell(head, com);
		}
	}
	return (com->ret);
}
