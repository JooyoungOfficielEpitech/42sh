/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** task6
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	int ff = 0;

	while (s1[ff] == s2[ff] && s1[ff] != '\0' && n != 0) {
		ff++;
		n--;
	}
	return (s1[ff] - s2[ff]);
}
