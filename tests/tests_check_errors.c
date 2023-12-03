/*
** EPITECH PROJECT, 2023
** tests_check_errors_server.c
** File description:
** tests_check_errors_server
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

Test(check_errors, valid_input_number)
{
    char *argv[] = {"./myteams_server", "8080"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    int result = check_errors(argc, argv);

    cr_assert_eq(result, SUCCESS);
}

Test(check_errors, invalid_input_non_number, .exit_code = ERROR)
{
    char *argv[] = {"./myteams_server", "not_a_number"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    check_errors(argc, argv);
    cr_assert_fail("Expected check_errors to exit with ERROR");
}

Test(check_errors, help_option, .exit_code = SUCCESS)
{
    char *argv[] = {"./myteams_server", "-help"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    check_errors(argc, argv);
    cr_assert_fail("Expected check_errors to exit with HELP");
}

Test(check_errors, one_arg, .exit_code = ERROR)
{
    char *argv[] = {"./myteams_server"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    check_errors(argc, argv);
    cr_assert_fail("Expected check_errors to exit with ERROR");
}
