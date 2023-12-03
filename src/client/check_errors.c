/*
** EPITECH PROJECT, 2023
** check_errors_client.c
** File description:
** check_errors_client
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "client.h"

int check_errors(int ac, char *av[])
{
    if (ac == 3 && IS_NUMBER(av[2]))
        return SUCCESS;
    ac == 2 && !strcmp(av[1], "-help") ? exit(HELP) : exit(ERROR);
}
