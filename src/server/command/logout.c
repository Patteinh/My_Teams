/*
** EPITECH PROJECT, 2023
** logout.c
** File description:
** logout
*/

#include <string.h>
#include "command.h"

void logout_teams(client_t *clt)
{
    memset(clt->use_team_uuid, 0, strlen(clt->use_team_uuid));
    memset(clt->use_channel_uuid, 0, strlen(clt->use_channel_uuid));
    memset(clt->use_thread_uuid, 0, strlen(clt->use_thread_uuid));
    clt->current_use = USE_NONE;
    if (clt->is_log) {
        for (client_t *tmp = *get_clients(); tmp; tmp = tmp->next)
            tmp->is_log ?
            my_send(tmp->socket, RFC_220.response, clt->uuid, clt->name) : 0;
        server_event_user_logged_out(clt->uuid);
    }
    clt->is_log = false;
}
