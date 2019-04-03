/*
** EPITECH PROJECT, 2017
** str_to_word_array.c
** File description:
** conv *str to **str
*/

#include <stdlib.h>
#include "my.h"

static	int	get_token_nbr(char *str, char delim)
{
	int token_nbr = 1;

	if (my_strlen(str) == 0)
		return (0);
	for (int i = 0 ; str[i] ; i++)
		if (str[i] == delim)
			token_nbr++;
	return (token_nbr);
}

static	int	*get_lengths(char *str, char delim, int token_nbr)
{
	int *lengths = malloc(sizeof(int) * token_nbr);
	int i = 0;
	int j = 0;

	if (!lengths)
		return (NULL);
	for (; j < token_nbr ; j++)
		lengths[j] = 0;
	j = 0;
	for (; str[i] ; i++) {
		lengths[j]++;
		if (str[i] == delim) {
			lengths[j]--;
			j++;
		}
	}
	return (lengths);
}

static	char	**tok_array_malloc(int token_nbr, int *lengths)
{
	char **result;

	result = malloc(sizeof(char *) * (token_nbr + 1));
	if (!result)
		return (NULL);
	result[token_nbr] = NULL;
	for (int i = 0 ; i < token_nbr ; i++) {
		result[i] = malloc(sizeof(char) * (lengths[i] + 1));
		if (!result[i])
			return (NULL);
		result[i][lengths[i]] = '\0';
	}
	return (result);
}

static	char	**fill_tokens(char *str, char delim, char **result)
{
	int j = 0;
	int k = 0;

	for (int i = 0 ; str[i] ; i++) {
		if (str[i] == delim) {
			j++;
			k = 0;
		}
		else {
			result[j][k] = str[i];
			k++;
		}
	}
	result[j] = NULL;
	return (result);
}

char	**my_strtok(char *str, char delim)
{
	int token_nbr = get_token_nbr(str, delim);
	int *lengths = get_lengths(str, delim, token_nbr);
	char **result;

	if (token_nbr == 0 || !lengths)
		return (NULL);
	result = tok_array_malloc(token_nbr, lengths);
	if (!result)
		return (NULL);
	free(lengths);
	result = fill_tokens(str, delim, result);
	return (result);
}
