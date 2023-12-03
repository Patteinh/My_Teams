/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "server.h"

int main(int ac, char *av[])
{
    return !check_errors(ac, av) ? server(av[1]) : ERROR;
}
