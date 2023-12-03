/*
** EPITECH PROJECT, 2023
** send.c
** File description:
** send
*/

#include <string.h>
#include "command.h"
#include "data.h"

void send_teams(client_t *clt)
{
    client_t *receiver = find_client_uuid(clt->cmd[1]);

    if (!receiver)
        return my_send(clt->socket, RFC_400.response, clt->cmd[1]);
    if (strlen(clt->cmd[2]) > MAX_BODY_LEN || !strcmp(clt->cmd[2], EMPTY))
        return my_send(clt->socket, RFC_510.response);
    create_discussion(clt);
    server_event_private_message_sended(clt->uuid, receiver->uuid, clt->cmd[2]);
    my_send(receiver->socket, RFC_290.response, clt->uuid, clt->cmd[2]);
}
