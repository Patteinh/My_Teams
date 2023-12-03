/*
** EPITECH PROJECT, 2023
** users.c
** File description:
** users
*/

#include <string.h>
#include "command.h"

void users_teams(client_t *clt)
{
    for (client_t *tmp = *get_clients(); tmp; tmp = tmp->next)
        if (strlen(tmp->name))
            my_send(clt->socket, RFC_340.response, tmp->uuid,
            tmp->name, tmp->is_log ? "1" : "0");
}
