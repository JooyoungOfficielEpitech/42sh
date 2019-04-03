/*
** EPITECH PROJECT, 2018
** my_putstr_test.c
** File description:
** my_putstr_test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_putstr(char const *str);

void	redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(my_putstr, test1, .init = redirect_all_std)
{
	my_putstr("salut");
	cr_assert_stdout_eq_str("salut");
}

Test(my_putstr, test4, .init = redirect_all_std)
{
	my_putstr("J'aime les croquodiles et les chiens.");
	cr_assert_stdout_eq_str("J'aime les croquodiles et les chiens.");
}
