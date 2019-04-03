/*
** EPITECH PROJECT, 2018
** can execute binary
** File description:
** bin
*/

#include "my.h"
#include "sh.h"

void plus(int pid, char **tab, char **env, command *com)
{
	if (pid == -1) {
		my_putstr("pid error\n");
		com->ret = 84;
	}
	else if (pid == 0) {
		execve(tab[0], tab, env);
		exit(exec_path(tab, com));
	}
}

int exec_bin(char **tab, char **env, command *com)
{
	int w, i = 0;
	int pid = fork();

	if (pid == -1 || pid == 0)
		plus(pid, tab, env, com);
	else {
		waitpid(pid, &w, 0);
		if (w == 139) {
			my_putstr("Segmentation fault");
			i = 1;
			com->ret = 139;
		}
		if (WCOREDUMP(w))
			my_putstr(" (core dumped)");
		if (i == 1) {
			my_putstr("\n");
			return (139);
		}
	}
	return (WEXITSTATUS(w));
}
