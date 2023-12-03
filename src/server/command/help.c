/*
** EPITECH PROJECT, 2023
** help.c
** File description:
** help
*/

#include "command.h"

void help_teams(client_t *clt)
{
    my_send(clt->socket, RFC_100.response);
}
