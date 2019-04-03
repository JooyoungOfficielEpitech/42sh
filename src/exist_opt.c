/*
** EPITECH PROJECT, 2018
** exitt_opt.c
** File description:
** opt
*/

int exist_opt(char *str, int pos)
{
	if (str[pos + 1] == '|' || str[pos + 1] == '<' || str[pos + 1] == '>')
		return (1);
	if (str[pos + 1] == ';' || str[pos + 1] == ',' || str[pos + 1] == '&')
		return (1);
	return (0);
}

int go_forward(char *str, int end)
{
	int save = end;

	end++;
	while (str[end]) {
		if (str[end] == ' ') {
			return (end - save);
		}
		end++;
	}
	return (end - save);
}
