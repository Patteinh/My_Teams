/*
** EPITECH PROJECT, 2023
** messages.c
** File description:
** messages
*/

#include <stdlib.h>
#include <string.h>
#include "command.h"

bool is_valid_discussion
(discussion_t *disc, const char *cmd_uuid, const char *user_uuid)
{
    return ((!strcmp(disc->receiver_uuid, cmd_uuid) &&
    !strcmp(disc->sender_uuid, user_uuid)) ||
    (!strcmp(disc->sender_uuid, cmd_uuid) &&
    !strcmp(disc->receiver_uuid, user_uuid)));
}

void messages_teams(client_t *clt)
{
    size_t nb_disc = 0;
    char *timestamp;

    if (!find_client_uuid(clt->cmd[1]))
        return my_send(clt->socket, RFC_400.response, clt->cmd[1]);
    for (discussion_t *tmp = *get_discussions(); tmp; tmp = tmp->next) {
        if (is_valid_discussion(tmp, clt->cmd[1], clt->uuid)) {
            timestamp = time_to_string(tmp->timestamp);
            my_send(clt->socket, RFC_390.response, tmp->sender_uuid,
            timestamp, tmp->body);
            free(timestamp);
            nb_disc++;
        }
    }
    nb_disc == 0 ? my_send(clt->socket, RFC_490.response) : 0;
}
