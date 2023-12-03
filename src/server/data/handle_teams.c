/*
** EPITECH PROJECT, 2023
** handle_teams.c
** File description:
** handle_teams
*/

#include <string.h>
#include <stdlib.h>
#include "data.h"

static void set_data_new_team(team_t *new, client_t *clt)
{
    char *uuid_str;
    GIVE_UUID(uuid_str);

    strncpy(new->uuid, uuid_str, UUID_STR_LEN - 1);
    new->uuid[UUID_STR_LEN - 1] = '\0';
    strcpy(new->name, clt->cmd[1]);
    strcpy(new->description, clt->cmd[2]);
    new->next = NULL;
    free(uuid_str);
}

static void add_team_to_others(team_t *new)
{
    get_teams() ? new->next = *get_teams() : 0;
    *get_teams() = new;
}

void create_team(client_t *clt)
{
    team_t *new = malloc(sizeof(*new));

    set_data_new_team(new, clt);
    add_team_to_others(new);
}
