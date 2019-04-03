/*
** EPITECH PROJECT, 2018
** my_putstr_test.c
** File description:
** my_putstr_test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(rm_spacer, test1)
{
	rm_spacer("salut          ça   va ?");
	cr_assert_stdout_eq_str("salut ça va?");
}

Test(rm_spacer, test2)
{
	rm_spacer("ls                     -l              -a");
	cr_assert_stdout_eq_str("ls -l -a");
}
