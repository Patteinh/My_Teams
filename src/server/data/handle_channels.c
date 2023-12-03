/*
** EPITECH PROJECT, 2023
** handle_channels.c
** File description:
** handle_channels
*/

#include <string.h>
#include <stdlib.h>
#include "data.h"

static void set_data_new_channel(channel_t *new, client_t *clt)
{
    char *uuid_str;
    GIVE_UUID(uuid_str);

    strncpy(new->uuid, uuid_str, UUID_STR_LEN - 1);
    new->uuid[UUID_STR_LEN - 1] = '\0';
    strcpy(new->name, clt->cmd[1]);
    strcpy(new->team_uuid, clt->use_team_uuid);
    strcpy(new->description, clt->cmd[2]);
    new->next = NULL;
    free(uuid_str);
}

static void add_channel_to_others(channel_t *new)
{
    get_channels() ? new->next = *get_channels() : 0;
    *get_channels() = new;
}

void create_channel(client_t *clt)
{
    channel_t *new = malloc(sizeof(*new));

    set_data_new_channel(new, clt);
    add_channel_to_others(new);
}
