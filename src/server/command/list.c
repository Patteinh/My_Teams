/*
** EPITECH PROJECT, 2023
** list.c
** File description:
** list
*/

#include <stdlib.h>
#include <string.h>
#include "command.h"

static void list_all_teams(client_t *clt)
{
    size_t nb_team = 0;

    for (team_t *tmp = *get_teams(); tmp; tmp = tmp->next) {
        my_send(clt->socket, RFC_350.response,
        tmp->uuid, tmp->name, tmp->description);
        nb_team++;
    }
    nb_team == 0 ? my_send(clt->socket, RFC_450.response) : 0;
}

static void list_all_channels(client_t *clt)
{
    size_t nb_channel = 0;

    for (channel_t *tmp = *get_channels(); tmp; tmp = tmp->next)
        if (!strcmp(tmp->team_uuid, clt->use_team_uuid)) {
            my_send(clt->socket, RFC_360.response,
            tmp->uuid, tmp->name, tmp->description);
            nb_channel++;
        }
    nb_channel == 0 ? my_send(clt->socket, RFC_460.response) : 0;
}

static void list_all_threads(client_t *clt)
{
    size_t nb_thread = 0;
    char *timestamp;

    for (thread_t *tmp = *get_threads(); tmp; tmp = tmp->next)
        if (!strcmp(tmp->channel_uuid, clt->use_channel_uuid)) {
            timestamp = time_to_string(tmp->timestamp);
            my_send(clt->socket, RFC_370.response, tmp->uuid,
            tmp->creator_uuid, timestamp, tmp->title, tmp->body);
            free(timestamp);
            nb_thread++;
        }
    nb_thread == 0 ? my_send(clt->socket, RFC_470.response) : 0;
}

static void list_all_replies(client_t *clt)
{
    size_t nb_replie = 0;
    char *timestamp;

    for (reply_t *tmp = *get_replies(); tmp; tmp = tmp->next)
        if (!strcmp(tmp->thread_uuid, clt->use_thread_uuid)) {
            timestamp = time_to_string(tmp->timestamp);
            my_send(clt->socket, RFC_380.response, tmp->thread_uuid,
            tmp->creator_uuid, timestamp, tmp->body);
            free(timestamp);
            nb_replie++;
        }
    nb_replie == 0 ? my_send(clt->socket, RFC_480.response) : 0;
}

void list_teams(client_t *clt)
{
    clt->current_use == USE_NONE ? list_all_teams(clt) : 0;
    clt->current_use == USE_TEAM ? list_all_channels(clt) : 0;
    clt->current_use == USE_CHANNEL ? list_all_threads(clt) : 0;
    clt->current_use == USE_THREAD ? list_all_replies(clt) : 0;
}
