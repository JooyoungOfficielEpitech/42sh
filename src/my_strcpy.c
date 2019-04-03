/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** task1
*/

char *my_strcpy(char *dest, char const *src)
{
	int prout = 0;

	while (src[prout] != '\0') {
		dest[prout] = src[prout];
		prout++;
	}
	dest[prout] = '\0';
	return (dest);
}
