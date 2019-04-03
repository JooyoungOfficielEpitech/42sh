/*
** EPITECH PROJECT, 2018
** my.h for the project minishell
** File description:
** minishell
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "sh.h"

int how_many_are_we(char *str, char a);
int my_get_nbr(char const *str);
int my_strcmp(char *one, char *two);
int my_strlen(char *str);
char **my_str_to_word_array(char *str);
int how_many_char_star(char **tab);
void my_putstr(char *str);
char *my_strdup(char *str);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *rm_space(char *str);
char **my_strtok(char *str, char delim);
char *my_concat(char *s1, char *s2);
char *end_of_str(const char *s1);
void set_and_err(int, char **, command *, char **);
void exit_and_rmv(void);
void set_com(command *com, char **env);

/* extras */

char *aliases(char *);
int is_arg(char *);
int do_not_exist(char **);
int send_valid_line(char *, char *);

void check_file(void);
int history(char *);

#endif
