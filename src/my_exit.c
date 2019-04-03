/*
** EPITECH PROJECT, 2018
** my_exit.c
** File description:
** exit.c
*/

#include "my.h"
#include "sh.h"

int is_nb(char *one)
{
	int i = 0, ret = 0;

	while (one[i]) {
		if (one[i] < 47 || one[i] > 57) {
			ret = -1;
			break;
		}
		i++;
	}
	return (ret);
}
void my_exit(char **tab)
{
	if (how_many_char_star(tab) > 2)
		my_putstr("exit: Expresion Syntax.\n");
	else if (how_many_char_star(tab) == 1) {
		my_putstr("exit\n");
		exit(0);
	}
	else if (is_nb(tab[1]) != 0)
		my_putstr("exit: Expression Syntax.\n");
	else {
		my_putstr("exit\n");
		exit(my_get_nbr(tab[1]));
	}
}
