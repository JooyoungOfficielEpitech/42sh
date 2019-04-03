/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** parses the command
*/

#include "sh.h"
#include <stdio.h>
#include <stdlib.h>

char **create_commands(char *str, int *type, int *beg, int *end)
{
	char **ret;
	int add = 0;

	*beg = *end;
	*type = define_type(str, *beg);
	while (str[*end]) {
		if (str[*end + 1] && exist_opt(str, *end) == 1) {
			add = go_forward(str, *end);
			break;
		}
		*end = *end + 1;
	}
	ret = my_str_to_word_array(my_cutstr(str, *beg, *end));
	*end = *end + add;
	return (ret);
}

void append_link(int type, char **commands, list_t *head)
{
	list_t *new = malloc(sizeof(list_t));

	new->commands = commands;
	new->next = head->next;
	new->type = type;
	head->next = new;
}

list_t *parsing_commands(char *str)
{
	list_t *head = malloc(sizeof(list_t));
	list_t *save = head;
	int beg = 0;
	int end = 0;
	char **commands;
	int type = 0;

	while (str[end]) {
		commands = create_commands(str, &type, &beg, &end);
		append_link(type, commands, head);
		head = head->next;
	}
	head->next = NULL;
	head = save->next;
	return (head);
}
