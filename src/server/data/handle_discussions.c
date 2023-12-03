/*
** EPITECH PROJECT, 2023
** handle_discussions.c
** File description:
** handle_discussions
*/

#include <string.h>
#include <stdlib.h>
#include "data.h"

static void set_data_new_discussion(discussion_t *new, client_t *clt)
{
    time_t timestamp = time(NULL);

    strcpy(new->sender_uuid, clt->uuid);
    strcpy(new->receiver_uuid, clt->cmd[1]);
    new->timestamp = timestamp;
    strcpy(new->body, clt->cmd[2]);
    new->next = NULL;
}

static void add_discussion_to_others(discussion_t *new)
{
    get_discussions() ? new->next = *get_discussions() : 0;
    *get_discussions() = new;
}

void create_discussion(client_t *clt)
{
    discussion_t *new = malloc(sizeof(*new));

    set_data_new_discussion(new, clt);
    add_discussion_to_others(new);
}
