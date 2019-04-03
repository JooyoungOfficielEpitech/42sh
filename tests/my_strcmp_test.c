/*
** EPITECH PROJECT, 2018
** strcmp_test
** File description:
** strcmp_test
*/

#include <criterion/criterion.h>
#include "my.h"

int my_strcmp(char *one, char *two);

Test(my_strcmp, test1)
{
	cr_assert_eq(my_strcmp("jaimeleslicornes", "jaimeleslicornes"), 1);
}

Test(my_strcmp, test2)
{
	cr_assert_eq(my_strcmp("licornevolante", "licornevolante"), 1);
}

Test(my_strcmp, test3)
{
	cr_assert_eq(my_strcmp("petitelicorne", "abcdefg"), 0);
}

Test(my_strcmp, test4)
{
	cr_assert_eq(my_strcmp(" ", "abcdef"), 0);
}

Test(my_strcmp, test6)
{
	cr_assert_eq(my_strcmp("jaime", ""), 0);
}
