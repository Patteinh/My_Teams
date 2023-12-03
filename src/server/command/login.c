/*
** EPITECH PROJECT, 2023
** login.c
** File description:
** login
*/

#include <stdlib.h>
#include <string.h>
#include "command.h"

static void copy_data_for_client(client_t **clt, client_t *other_clt)
{
    strcpy((*clt)->uuid, other_clt->uuid);
    strcpy((*clt)->name, other_clt->name);
    strcpy((*clt)->use_team_uuid, other_clt->use_team_uuid);
    strcpy((*clt)->use_channel_uuid, other_clt->use_channel_uuid);
    strcpy((*clt)->use_thread_uuid, other_clt->use_thread_uuid);
    (*clt)->current_use = other_clt->current_use;
    (*clt)->is_log = true;
    (*clt)->online = true;
}

static int is_client_existing(client_t *clt)
{
    client_t *other_clt = find_client_name(clt->cmd[1]);

    if (!other_clt) {
        strcpy(clt->name, clt->cmd[1]);
        server_event_user_created(clt->uuid, clt->name);
        clt->is_log = true;
        return SUCCESS;
    }
    if (other_clt == clt) {
        clt->is_log = true;
        return SUCCESS;
    }
    if (other_clt->is_log) {
        copy_data_for_client(&clt, other_clt);
        return SUCCESS;
    }
    copy_data_for_client(&clt, other_clt);
    remove_client(other_clt);
    return SUCCESS;
}

void login_teams(client_t *clt)
{
    if (strlen(clt->cmd[1]) > MAX_NAME_LEN || !strcmp(clt->cmd[1], EMPTY))
        return my_send(clt->socket, RFC_510.response);
    if (clt->is_log == true || is_client_existing(clt))
        return my_send(clt->socket, RFC_530.response);
    memset(clt->use_team_uuid, 0, strlen(clt->use_team_uuid));
    memset(clt->use_channel_uuid, 0, strlen(clt->use_channel_uuid));
    memset(clt->use_thread_uuid, 0, strlen(clt->use_thread_uuid));
    clt->current_use = USE_NONE;
    server_event_user_logged_in(clt->uuid);
    for (client_t *tmp = *get_clients(); tmp; tmp = tmp->next)
        if (tmp->is_log)
            my_send(tmp->socket, RFC_210.response, clt->uuid, clt->name);
}
