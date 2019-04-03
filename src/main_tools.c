/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** main_tools.c
*/

#include "my.h"

void set_and_err(int ac, char **av, command *com, char **env)
{
	(ac > 1 && av[1] != NULL) ? exit(84) : NULL;
	set_com(com, env);
	check_file();
}

void exit_and_rmv(void)
{
	my_putstr("exit\n");
	remove(".history");
}
