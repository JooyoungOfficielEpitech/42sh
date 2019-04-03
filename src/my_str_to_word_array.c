/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
**
*/

#include <stdlib.h>

int cpt_word(char *str)
{
	int i;
	int cpt;
	char car_prec;

	i = 0;
	cpt = 0;
	car_prec = ' ';
	while (str[i] != '\0') {
		if ((car_prec == ' ') && (str[i] != ' ')) {
			cpt++;
		}
		car_prec = str[i];
		i++;
	}
	return (cpt);
}

char *copy(char *str, char *dest, int debut)
{
	int i = 0;

	while ((str[debut] != ' ') && (str[debut] != '\0')) {
		dest[i] = str[debut];
		debut++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int cpt_letter(char *str, int debut)
{
	int i = 0;

	while ((str[debut] != ' ') && (str[debut] != '\0')) {
		debut++;
		i++;
	}
	return (i);
}

char **my_str_to_word_array(char *s)
{
	int i;
	int j;
	char car_prec;
	char **tab;

	i = j = 0;
	tab = malloc((cpt_word(s) + 1) * sizeof(*tab));
	car_prec = ' ';
	while (s[i] != '\0') {
		if ((car_prec == ' ') && (s[i] != ' ')) {
			tab[j] = malloc((cpt_letter(s, i) + 1) * sizeof(**tab));
			copy(s, tab[j], i);
			j++;
		}
		car_prec = s[i];
		i++;
	}
	tab[j] = '\0';
	return (tab);
}
