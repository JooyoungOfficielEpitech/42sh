/*
** EPITECH PROJECT, 2018
** write_on_file.c
** File description:
** write msgs on file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "sh.h"

void write_on_file(list_t *head, command *com, int *pipefd)
{
	int file = open(head->next->commands[0], O_CREAT | \
			O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
	char *buf = malloc(sizeof(char));

	while (read(pipefd[0], buf, 1) != 0) {
		write(file, buf, 1);
	}
}
