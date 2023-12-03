/*
** EPITECH PROJECT, 2023
** user.c
** File description:
** user
*/

#include <string.h>
#include "command.h"

void user_teams(client_t *clt)
{
    client_t *clt_searched = find_client_uuid(clt->cmd[1]);

    if (clt_searched)
        return my_send(clt->socket, RFC_300.response, clt_searched->uuid,
        clt_searched->name, clt_searched->is_log ? "1" : "0");
    my_send(clt->socket, RFC_400.response, clt->cmd[1]);
}
