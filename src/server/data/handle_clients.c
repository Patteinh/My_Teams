/*
** EPITECH PROJECT, 2023
** handle_clients.c
** File description:
** handle_clients
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "command.h"
#include "server.h"

void remove_client(client_t *clt)
{
    client_t **current_clt = get_clients();

    while (*current_clt) {
        if (*current_clt == clt) {
            *current_clt = (*current_clt)->next;
            free(clt);
            return;
        }
        current_clt = &(*current_clt)->next;
    }
}

void disconnect_client(client_t *clt)
{
    SERVER_DISCONNECTION(clt->socket);
    if (clt->is_log) {
        for (client_t *tmp = *get_clients(); tmp; tmp = tmp->next)
            tmp->is_log ?
            my_send(tmp->socket, RFC_220.response, clt->uuid, clt->name) : 0;
        server_event_user_logged_out(clt->uuid);
    }
    close(clt->socket);
    clt->is_log = false;
    clt->online = false;
    memset(clt->use_team_uuid, 0, strlen(clt->use_team_uuid));
    memset(clt->use_channel_uuid, 0, strlen(clt->use_channel_uuid));
    memset(clt->use_thread_uuid, 0, strlen(clt->use_thread_uuid));
    clt->current_use = USE_NONE;
}

static void set_data_new_client(client_t *new, int new_socket)
{
    char *uuid_str;
    GIVE_UUID(uuid_str);

    strncpy(new->uuid, uuid_str, UUID_STR_LEN - 1);
    new->uuid[UUID_STR_LEN - 1] = '\0';
    memset(new->name, 0, MAX_NAME_LEN);
    memset(new->use_team_uuid, 0, UUID_STR_LEN);
    memset(new->use_channel_uuid, 0, UUID_STR_LEN);
    memset(new->use_thread_uuid, 0, UUID_STR_LEN);
    new->current_use = USE_NONE;
    new->socket = new_socket;
    new->is_log = false;
    new->online = true;
    new->next = NULL;
    free(uuid_str);
}

static void add_new_client_to_others(client_t *new)
{
    get_clients() ? new->next = *get_clients() : 0;
    *get_clients() = new;
}

void create_client(int new_socket)
{
    client_t *new = malloc(sizeof(*new));

    set_data_new_client(new, new_socket);
    add_new_client_to_others(new);
}
