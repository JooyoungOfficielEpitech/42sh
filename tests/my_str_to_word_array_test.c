/*
** EPITECH PROJECT, 2018
** dsdsd
** File description:
** sdsd
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_to_word_array, test1)
{
	char *tab[] = {"J'aime", "les", "licornes"};

	cr_assert_eq(my_str_to_word_array("J'aime les licornes"), tab);
}
