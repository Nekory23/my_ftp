/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** test_display_help
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ftp.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display_help, return_val, .init=redirect_all_stdout)
{
    int ac = 2;
    char *av[] = {"./myftp", "-help"};

    cr_assert_eq(start(ac, av), 0);
}