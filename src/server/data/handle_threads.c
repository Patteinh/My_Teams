/*
** EPITECH PROJECT, 2023
** handle_threads.c
** File description:
** handle_threads
*/

#include <string.h>
#include <stdlib.h>
#include "data.h"

static void set_data_new_thread(thread_t *new, client_t *clt)
{
    char *uuid_str;
    GIVE_UUID(uuid_str);
    time_t timestamp = time(NULL);

    strncpy(new->uuid, uuid_str, UUID_STR_LEN - 1);
    new->uuid[UUID_STR_LEN - 1] = '\0';
    strcpy(new->channel_uuid, clt->use_channel_uuid);
    strcpy(new->creator_uuid, clt->uuid);
    strcpy(new->title, clt->cmd[1]);
    strcpy(new->body, clt->cmd[2]);
    new->timestamp = timestamp;
    new->next = NULL;
    free(uuid_str);
}

static void add_thread_to_others(thread_t *new)
{
    get_threads() ? new->next = *get_threads() : 0;
    *get_threads() = new;
}

void create_thread(client_t *clt)
{
    thread_t *new = malloc(sizeof(*new));

    set_data_new_thread(new, clt);
    add_thread_to_others(new);
}
