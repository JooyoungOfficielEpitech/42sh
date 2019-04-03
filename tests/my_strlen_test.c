/*
** EPITECH PROJECT, 2018
** criterion.c
** File description:
** criterion.c
*/

#include <criterion/criterion.h>

int my_strlen(char const *str);

Test(my_strlen, test1)
{
	cr_assert_eq(my_strlen("tomate"), strlen("tomate"));
}

Test(my_strlen, test2)
{
	cr_assert_eq(my_strlen(" "), strlen(" "));
}

Test(my_strlen, test3)
{
	cr_assert_eq(my_strlen(""), strlen(""));
}

Test(my_strlen, test5)
{
	cr_assert_eq(my_strlen("\0tomato"), strlen("\0tomato"));
}
