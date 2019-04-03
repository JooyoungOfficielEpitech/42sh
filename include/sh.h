/*
** EPITECH PROJECT, 2018
** include file of sh
** File description:
** sh
*/

#ifndef SH_H
#define SH_H

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct command {
	char **env;
	int i;
	int ret;
	char *past;
}command;

struct list_s {
	int type;
	char **commands;
	struct list_s *next;
};

typedef struct list_s list_t;

int exec_path(char **tab, command *command);
int exec_bin(char **tab, char **env, command *com);
void my_unsetenv(char **tab, command *com);
void my_setenv(char **tab, command *com);
void my_env(command *com);
void my_exit(char **tab);
int my_cd(char **tab, command *com);
char *slash_name(char *str, char *name);
char *eq(char *str);
char *my_instr(char *str);
char *my_home(command *command);
char *make_path(char *str, int n);
char **my_setenv_new(char **env, char *obj);
char **path(char **env);
char *my_instr(char *str);
int env_find(char **tab, char **env);
int is_eq_there(char *str);
char *rm_spacer(char *str);
int pipe_exec(char *av, command *com);
char **my_str_to_word_array(char *s);
char *my_cutstr(char *, int, int);
int define_type(char *, int);
int exist_opt(char *, int);
char *get_next_line(int);
int go_forward(char *, int);
list_t *parsing_commands(char *);
void pipe_execution(char **one, char **two, char **env, command *com);
void write_on_file(list_t *, command *, int *);
void testing_loop_shell(list_t *, command *, int);
void pipe_execution_double(list_t *, command *);
void read_execution(list_t *, command *, int);
void prompt(void);
void loop_shell(list_t *, command *, int);

#endif
