/*
** EPITECH PROJECT, 2018
** unit_test.c
** File description:
** unit_test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>
#include <stdio.h>

Test(gnl, test1)
{
	FILE *ref = fopen("get_next_line_test/man_gcc", "w+");
	FILE *my_file = fopen("get_next_line_test/gnl_test", "w+");

	cr_assert_file_contents_eq(my_file, ref);
}

Test(gnl, test2)
{
	FILE *ref = fopen("get_next_line_test/test1", "w+");
	FILE *my_file = fopen("get_next_line_test/gnl_test2", "w+");

	cr_assert_file_contents_eq(my_file, ref);
}

Test(gnl, test3)
{
	FILE *ref = fopen("get_next_line_test/test2", "w+");
	FILE *my_file = fopen("get_next_line_test/gnl_test3", "w+");

	cr_assert_file_contents_eq(my_file, ref);
}

Test(gnl, test4)
{
	FILE *ref = fopen("get_next_line_test/man_gcc", "w+");
	FILE *my_file = fopen("get_next_line_test/gnl_test4", "w+");

	cr_assert_file_contents_eq(my_file, ref);
}

Test(gnl, test5)
{
	FILE *ref = fopen("get_next_line_test/man_gcc", "w++");
	FILE *my_file = fopen("get_next_line_test/gnl_test5", "w++");

	cr_assert_file_contents_eq(my_file, ref);
}

Test(gnl, test6)
{
	FILE *ref = fopen("get_next_line_test/man_gcc", "w++");
	FILE *my_file = fopen("get_next_line_test/gnl_test6", "w++");

	cr_assert_file_contents_eq(my_file, ref);
}

Test(gnl, test7)
{
	FILE *ref = fopen("get_next_line_test/man_gcc", "w++");
	FILE *my_file = fopen("get_next_line_test/gnl_test7", "w++");

	cr_assert_file_contents_eq(my_file, ref);
}

Test(gnl, test8)
{
	FILE *ref = fopen("get_next_line_test/man_gcc", "w++");
	FILE *my_file = fopen("get_next_line_test/gnl_test8", "w++");

	cr_assert_file_contents_eq(my_file, ref);
}

Test(gnl, test9)
{
	FILE *ref = fopen("get_next_line_test/man_gcc", "w++");
	FILE *my_file = fopen("get_next_line_test/gnl_test9", "w++");

	cr_assert_file_contents_eq(my_file, ref);
}

Test(gnl, test10)
{
	FILE *ref = fopen("get_next_line_test/man_gcc", "w++");
	FILE *my_file = fopen("get_next_line_test/gnl_test10", "w++");

	cr_assert_file_contents_eq(my_file, ref);
}
