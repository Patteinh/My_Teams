/*
** EPITECH PROJECT, 2023
** use.c
** File description:
** use
*/

#include <string.h>
#include "command.h"
#include "data.h"

static void reset_use(client_t *clt)
{
    memset(clt->use_team_uuid, 0, UUID_STR_LEN);
    memset(clt->use_channel_uuid, 0, UUID_STR_LEN);
    memset(clt->use_thread_uuid, 0, UUID_STR_LEN);
    clt->current_use = USE_NONE;
}

static void use_team(client_t *clt)
{
    team_t *team = find_team_uuid(clt->cmd[1]);

    if (!team)
        return my_send(clt->socket, RFC_410.response, clt->cmd[1]);
    if (!is_subscribe(clt->uuid, clt->cmd[1]))
        return my_send(clt->socket, RFC_520.response);
    for (team_t *tmp = *get_teams(); tmp; tmp = tmp->next)
        if (!strcmp(clt->cmd[1], tmp->uuid)) {
            strcpy(clt->use_team_uuid, tmp->uuid);
            clt->current_use = USE_TEAM;
        }
    my_send(clt->socket, RFC_333.response);
}

static void use_channel(client_t *clt)
{
    channel_t *channel = find_channel_uuid(clt->cmd[2]);

    if (clt->current_use == USE_NONE)
        return;
    if (!channel)
        return my_send(clt->socket, RFC_420.response, clt->cmd[2]);
    for (channel_t *tmp = *get_channels(); tmp; tmp = tmp->next)
        if (!strcmp(clt->cmd[2], tmp->uuid)) {
            strcpy(clt->use_channel_uuid, tmp->uuid);
            clt->current_use = USE_CHANNEL;
        }
    my_send(clt->socket, RFC_336.response);
}

static void use_thread(client_t *clt)
{
    thread_t *thread = find_thread_uuid(clt->cmd[3]);

    if (clt->current_use == USE_NONE || clt->current_use == USE_TEAM)
        return;
    if (!thread)
        return my_send(clt->socket, RFC_430.response, clt->cmd[3]);
    for (thread_t *tmp = *get_threads(); tmp; tmp = tmp->next)
        if (!strcmp(clt->cmd[3], tmp->uuid)) {
            strcpy(clt->use_thread_uuid, tmp->uuid);
            clt->current_use = USE_THREAD;
        }
    my_send(clt->socket, RFC_339.response);
}

void use_teams(client_t *clt)
{
    reset_use(clt);
    if (my_arraylen(clt->cmd) - 1 == 0) {
        clt->current_use = USE_NONE;
        return;
    }
    my_arraylen(clt->cmd) - 1 == 1 ?
    use_team(clt) : 0;
    my_arraylen(clt->cmd) - 1 == 2 ?
    use_team(clt), use_channel(clt) : 0;
    my_arraylen(clt->cmd) - 1 == 3 ?
    use_team(clt), use_channel(clt), use_thread(clt) : 0;
}
