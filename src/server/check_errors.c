/*
** EPITECH PROJECT, 2023
** check_errors.c
** File description:
** check_errors
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "server.h"

int check_errors(int ac, char *av[])
{
    if (ac == 2 && IS_NUMBER(av[1]))
        return SUCCESS;
    ac == 2 && !strcmp(av[1], "-help") ? exit(HELP) : exit(ERROR);
}
