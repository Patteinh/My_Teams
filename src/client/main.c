/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "client.h"

int main(int ac, char *av[])
{
    return !check_errors(ac, av) ? client(av[1], av[2]) : ERROR;
}
