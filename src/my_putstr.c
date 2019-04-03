/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** got
*/

#include"my.h"

void my_putchar(char a)
{
	write(1, &a, 1);
}
void my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}
