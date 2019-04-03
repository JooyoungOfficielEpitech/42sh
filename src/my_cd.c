/*
** EPITECH PROJECT, 2018
** mly_cd.c
** File description:
** cd
*/

#include "sh.h"
#include "my.h"

char *my_home(command *command)
{
	int i = 0;

	while (command->env[i]) {
		if (my_strncmp(command->env[i], "HOME=", 4) == 0)
			return (make_path(command->env[i], 5));
		i++;
	}

	return (".");
}
char *my_old(command *com)
{
	int i = 0;

	while (com->env[i]) {
		if (my_strncmp(com->env[i], "OLDPWD=", 6) == 0)
			return (make_path(com->env[i], 7));
		i++;
	}
	my_putstr(": No such file or directory.\n");

	return (".");
}
int msg_err(command *com, int type, char **tab)
{
	if (type == 1) {
		com->ret = 1;
		my_putstr(tab[1]);
		my_putstr(": Permition denied.\n");
		return (1);
	}
	else if (type == 2) {
		com->ret = 1;
		my_putstr(tab[1]);
		my_putstr(": Not a directory.\n");
		return (1);
	}
	else if (type == 3) {
		my_putstr(tab[1]);
		my_putstr(": No such file or directory.\n");
		com->ret = 1;
		return (1);
	}
	return (0);
}
int change_dir(char **tab, command *com, int type)
{
	char buf[100];
	char *boom[] = { "setenv", "OLDPWD", buf, NULL };
	int cd;

	getcwd(buf, 100);
	if (type == 1) {
		com->ret = 0;
		my_setenv(boom, com);
		cd = chdir(my_home(com));
	}
	else if (type == 2) {
		com->ret = 0;
		my_setenv(boom, com);
		cd = chdir(tab[1]);
	}
	else if (type == 3) {
		com->ret = 0;
		cd = chdir(my_old(com));
		my_setenv(boom, com);
	}
	return (cd);
}
int my_cd(char **tab, command *com)
{
	int cd;

	if (how_many_char_star(tab) == 1)
		cd = change_dir(tab, com, 1);
	else if (how_many_char_star(tab) > 2) {
		my_putstr("cd: Too many arguments.\n");
		return (1);
	} else {
		if (tab[1][0] == '-')
			cd = change_dir(tab, com, 3);
		else
			cd = change_dir(tab, com, 2);
	}
	if (errno == EACCES)
		cd = msg_err(com, 1, tab);
	else if (errno == ENOTDIR)
		cd = msg_err(com, 2, tab);
	else
		if (cd != 0)
			cd = msg_err(com, 3, tab);
	return (cd);
}
