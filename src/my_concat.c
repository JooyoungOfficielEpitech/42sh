/*
** EPITECH PROJECT, 2018
** my_concat.c
** File description:
** add two str
*/

#include <string.h>
#include <stdlib.h>

char *my_concat(char *s1, char *s2)
{
	char *result = malloc(strlen(s1) + strlen(s2) + 2);

	if (!result)
		exit(84);
	if (s1[0] == '\0')
		return (s2);
	strcpy(result, s1);
	strcat(result, "\n");
	strcat(result, s2);
	return (result);
}

char *end_of_str(const char *s1)
{
	char *result = malloc(strlen(s1) + 2);

	if (!result)
		exit(84);
	strcpy(result, s1);
	strcat(result, "\n");
	return (result);
}
