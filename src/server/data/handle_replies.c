/*
** EPITECH PROJECT, 2023
** handle_replies.c
** File description:
** handle_replies
*/

#include <string.h>
#include <stdlib.h>
#include "data.h"

static void set_data_new_reply(reply_t *new, client_t *clt)
{
    char *uuid_str;
    GIVE_UUID(uuid_str);
    time_t timestamp = time(NULL);

    strncpy(new->uuid, uuid_str, UUID_STR_LEN - 1);
    new->uuid[UUID_STR_LEN - 1] = '\0';
    strcpy(new->creator_uuid, clt->uuid);
    strcpy(new->thread_uuid, clt->use_thread_uuid);
    strcpy(new->body, clt->cmd[1]);
    new->timestamp = timestamp;
    new->next = NULL;
    free(uuid_str);
}

static void add_reply_to_others(reply_t *new)
{
    get_replies() ? new->next = *get_replies() : 0;
    *get_replies() = new;
}

void create_reply(client_t *clt)
{
    reply_t *new = malloc(sizeof(*new));

    set_data_new_reply(new, clt);
    add_reply_to_others(new);
}
