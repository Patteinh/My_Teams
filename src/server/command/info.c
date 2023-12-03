/*
** EPITECH PROJECT, 2023
** info.c
** File description:
** info
*/

#include <stdlib.h>
#include "command.h"
#include "data.h"

static void info_user(client_t *clt)
{
    my_send(clt->socket, RFC_300.response, clt->uuid, clt->name, "1");
}

static void info_team(client_t *clt)
{
    team_t *team = find_team_uuid(clt->use_team_uuid);
    my_send(clt->socket, RFC_310.response, team->uuid,
    team->name, team->description);
}

static void info_channel(client_t *clt)
{
    channel_t *channel = find_channel_uuid(clt->use_channel_uuid);
    my_send(clt->socket, RFC_320.response, channel->uuid,
    channel->name, channel->description);
}

static void info_thread(client_t *clt)
{
    char *timestamp;
    thread_t *thread = find_thread_uuid(clt->use_thread_uuid);

    timestamp = time_to_string(thread->timestamp);
    my_send(clt->socket, RFC_330.response, thread->uuid,
    thread->creator_uuid, timestamp,
    thread->title, thread->body);
    free(timestamp);
}

void info_teams(client_t *clt)
{
    clt->current_use == USE_NONE ? info_user(clt) : 0;
    clt->current_use == USE_TEAM ? info_team(clt) : 0;
    clt->current_use == USE_CHANNEL ? info_channel(clt) : 0;
    clt->current_use == USE_THREAD ? info_thread(clt) : 0;
}
