/*
** EPITECH PROJECT, 2018
** my_env.c
** File description:
** env function
*/

#include "my.h"
#include "sh.h"

void my_env(command *com)
{
	int i = 0;

	com->ret = 0;
	while (com->env[i]) {
		my_putstr(com->env[i]);
		my_putstr("\n");
		i++;
	}
	return;
}
