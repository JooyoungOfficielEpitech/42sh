/*
** EPITECH PROJECT, 2018
** history
** File description:
** 42sh
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "my.h"

void check_file(void)
{
	int fd = open(".history", O_RDONLY);

	if (fd != -1)
		remove(".history");
	close(fd);
}

char *check_cmd(char *cmd, char *str)
{
	if (cmd == NULL)
		cmd = strdup(str);
	else if (strcmp(cmd, str) == 0)
		return (NULL);
	cmd = strdup(str);
	return (cmd);
}

void write_in_file(FILE *fd, int i, char *str)
{
	time_t secondes = time(&secondes);
	struct tm *instant = localtime(&secondes);

	if (instant->tm_min >= 10)
		fprintf(fd, " %d  %d:%d   %s\n" , \
		i, instant->tm_hour, instant->tm_min, str);
	else
		fprintf(fd, " %d  %d:0%d   %s\n" , \
		i, instant->tm_hour, instant->tm_min, str);
}

int times(char *str)
{
	static char *cmd = NULL;
	static int passage = 0;
	FILE *fd;

	if (cmd == NULL)
		cmd = strdup(str);
	else if (strcmp(cmd, str) == 0)
		return (0);
	cmd = strdup(str);
	fd = fopen(".history", "a");
	if (fd == NULL)
		return (1);
	passage++;
	write_in_file(fd, passage, str);
	fclose(fd);
	return (0);
}

int history(char *gnl)
{
	FILE *fp;
	size_t size = 0;
	char *str = malloc(size * sizeof(char));

	times(gnl);
	if (strcmp(gnl, "history") != 0)
		return (0);
	fp = fopen(".history", "r");
	while ((getline(&str, &size, fp)) != -1)
		printf("%s", str);
	fclose(fp);
	return (0);
}
