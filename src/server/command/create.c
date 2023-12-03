/*
** EPITECH PROJECT, 2023
** create.c
** File description:
** create
*/

#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "data.h"

static void add_team(client_t *clt)
{
    team_t *team;

    if (strlen(clt->cmd[1]) > MAX_NAME_LEN || !strcmp(clt->cmd[1], EMPTY) ||
    strlen(clt->cmd[2]) > MAX_DESCRIPTION_LEN || !strcmp(clt->cmd[2], EMPTY))
        return my_send(clt->socket, RFC_510.response);
    create_team(clt);
    team = find_team_name(clt->cmd[1]);
    server_event_team_created(team->uuid, team->name, clt->uuid);
    my_send(clt->socket, RFC_250.response, team->uuid, team->name,
    team->description);
    for (client_t *tmp = *get_clients(); tmp; tmp = tmp->next)
        if (tmp->is_log)
            my_send(tmp->socket, RFC_255.response, team->uuid, team->name,
            team->description);
}

static void add_channel(client_t *clt)
{
    channel_t *channel;

    if (!is_subscribe(clt->uuid, clt->use_team_uuid))
        return my_send(clt->socket, RFC_520.response);
    if (strlen(clt->cmd[1]) > MAX_NAME_LEN || !strcmp(clt->cmd[1], EMPTY) ||
    strlen(clt->cmd[2]) > MAX_DESCRIPTION_LEN || !strcmp(clt->cmd[2], EMPTY))
        return my_send(clt->socket, RFC_510.response);
    create_channel(clt);
    channel = find_channel_name(clt->cmd[1]);
    server_event_channel_created(channel->team_uuid,
    channel->uuid, channel->name);
    my_send(clt->socket, RFC_260.response, channel->uuid, channel->name,
    channel->description);
    for (client_t *tmp = *get_clients(); tmp; tmp = tmp->next)
        if (is_subscribe(tmp->uuid, clt->use_team_uuid) && tmp->is_log)
            my_send(tmp->socket, RFC_265.response, channel->uuid,
            channel->name, channel->description);
}

static void add_thread(client_t *clt)
{
    thread_t *thread;
    char *timestamp;

    if (!is_subscribe(clt->uuid, clt->use_team_uuid))
        return my_send(clt->socket, RFC_520.response);
    if (strlen(clt->cmd[1]) > MAX_NAME_LEN || !strcmp(clt->cmd[1], EMPTY) ||
    strlen(clt->cmd[2]) > MAX_DESCRIPTION_LEN || !strcmp(clt->cmd[2], EMPTY))
        return my_send(clt->socket, RFC_510.response);
    create_thread(clt);
    thread = find_thread_name(clt->cmd[1]);
    server_event_thread_created(thread->channel_uuid, thread->uuid,
    thread->creator_uuid, thread->title, thread->body);
    timestamp = time_to_string(thread->timestamp);
    my_send(clt->socket, RFC_270.response, thread->uuid,
    thread->creator_uuid, timestamp, thread->title, thread->body);
    for (client_t *tmp = *get_clients(); tmp; tmp = tmp->next)
        if (is_subscribe(tmp->uuid, clt->use_team_uuid) && tmp->is_log)
            my_send(tmp->socket, RFC_275.response, thread->uuid,
            thread->creator_uuid, timestamp, thread->title, thread->body);
    free(timestamp);
}

static void add_reply(client_t *clt)
{
    reply_t *reply;
    char *timestamp;

    if (!is_subscribe(clt->uuid, clt->use_team_uuid))
        return my_send(clt->socket, RFC_520.response);
    if (strlen(clt->cmd[1]) > MAX_BODY_LEN || !strcmp(clt->cmd[1], EMPTY))
        return my_send(clt->socket, RFC_510.response);
    create_reply(clt);
    reply = find_reply_uuid(clt->use_thread_uuid);
    server_event_reply_created(reply->thread_uuid,
    reply->creator_uuid, reply->body);
    timestamp = time_to_string(reply->timestamp);
    my_send(clt->socket, RFC_280.response, reply->thread_uuid,
    reply->creator_uuid, timestamp, reply->body);
    for (client_t *tmp = *get_clients(); tmp; tmp = tmp->next)
        if (is_subscribe(tmp->uuid, clt->use_team_uuid) && tmp->is_log)
            my_send(tmp->socket, RFC_285.response, clt->use_team_uuid,
            reply->thread_uuid, reply->creator_uuid, reply->body);
    free(timestamp);
}

void create_teams(client_t *clt)
{
    if ((my_arraylen(clt->cmd) - 1 == 1) && (clt->current_use == USE_NONE ||
    clt->current_use == USE_TEAM || clt->current_use == USE_CHANNEL))
        return my_send(clt->socket, RFC_510.response);
    clt->current_use == USE_NONE ? add_team(clt) : 0;
    clt->current_use == USE_TEAM ? add_channel(clt) : 0;
    clt->current_use == USE_CHANNEL ? add_thread(clt) : 0;
    clt->current_use == USE_THREAD ? add_reply(clt) : 0;
}
