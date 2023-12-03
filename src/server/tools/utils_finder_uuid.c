/*
** EPITECH PROJECT, 2023
** utils_finder.c
** File description:
** utils_finder
*/

#include <string.h>
#include "tools.h"

team_t *find_team_uuid(const char *uuid)
{
    for (team_t *node = *get_teams(); node; node = node->next)
        if (!strcmp(node->uuid, uuid))
            return node;
    return NULL;
}

channel_t *find_channel_uuid(const char *uuid)
{
    for (channel_t *node = *get_channels(); node; node = node->next)
        if (!strcmp(node->uuid, uuid))
            return node;
    return NULL;
}

thread_t *find_thread_uuid(const char *uuid)
{
    for (thread_t *node = *get_threads(); node; node = node->next)
        if (!strcmp(node->uuid, uuid))
            return node;
    return NULL;
}

client_t *find_client_uuid(const char *uuid)
{
    for (client_t *tmp = *get_clients(); tmp; tmp = tmp->next)
        if (!strcmp(tmp->uuid, uuid))
            return tmp;
    return NULL;
}

reply_t *find_reply_uuid(const char *uuid)
{
    for (reply_t *tmp = *get_replies(); tmp; tmp = tmp->next)
        if (!strcmp(tmp->thread_uuid, uuid))
            return tmp;
    return NULL;
}
