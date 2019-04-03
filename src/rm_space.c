/*
** EPITECH PROJECT, 2018
** test for the rm_space function
** File description:
** t
*/

#include "my.h"

char *clean_str(char *str)
{
	int o = 0;

	while (str[o] != '\0') {
		if (str[o] == '\t')
			str[o] = ' ';
		o = o + 1;
	}
	return (str);
}

char *rm_spacer(char *str)
{
	int o = 0;
	int b = 0;

	str = clean_str(str);
	while (str[o] == ' ')
		o = o + 1;
	while (str[o] != '\0') {
		if ((str[o] != ' ' || str[o + 1] != ' ') && \
		(str[o] != ' ' || str[o + 1] != '\0')) {
			str[b] = str[o];
			b = b + 1;
			o = o + 1;
		}
		else
			o = o + 1;
	}
	str[b] = '\0';
	return (str);
}
