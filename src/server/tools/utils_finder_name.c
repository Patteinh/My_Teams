/*
** EPITECH PROJECT, 2023
** utils_finder_name.c
** File description:
** utils_finder_name
*/

#include <string.h>
#include "tools.h"

team_t *find_team_name(const char *name)
{
    for (team_t *node = *get_teams(); node; node = node->next)
        if (!strcmp(node->name, name))
            return node;
    return NULL;
}

channel_t *find_channel_name(const char *name)
{
    for (channel_t *node = *get_channels(); node; node = node->next)
        if (!strcmp(node->name, name))
            return node;
    return NULL;
}

thread_t *find_thread_name(const char *name)
{
    for (thread_t *node = *get_threads(); node; node = node->next)
        if (!strcmp(node->title, name))
            return node;
    return NULL;
}

client_t *find_client_name(const char *name)
{
    for (client_t *node = *get_clients(); node; node = node->next)
        if (!strcmp(node->name, name))
            return node;
    return NULL;
}
