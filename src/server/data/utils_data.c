/*
** EPITECH PROJECT, 2023
** utils_data.c
** File description:
** utils_data
*/

#include <stdlib.h>
#include <string.h>
#include "data.h"

bool is_subscribe(const char *uuid, const char *searched_uuid)
{
    for (subscription_t *tmp = *get_subscriptions(); tmp; tmp = tmp->next)
        if (!strcmp(tmp->user_uuid, uuid) &&
        !strcmp(tmp->team_uuid, searched_uuid))
            return true;
    return false;
}

static void remove_client(client_t **head, client_t **prev, client_t **clt)
{
    if (*prev) {
        (*prev)->next = (*clt)->next;
    } else {
        *head = (*clt)->next;
    }
    free(*clt);
    *clt = *prev ? (*prev)->next : *head;
}

void remove_duplicates(client_t *curr)
{
    client_t *tmp;
    client_t *prev = curr;

    for (tmp = curr->next; tmp;) {
        if (!strcmp(curr->name, tmp->name)) {
            prev->next = tmp->next;
            free(tmp);
            tmp = prev->next;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

void remove_user_same_name(client_t **head)
{
    client_t *curr;

    for (curr = *head; curr; curr = curr->next)
        remove_duplicates(curr);
}

void clean_server_data(void)
{
    client_t *head = *get_clients();
    client_t *prev = NULL;

    for (client_t *clt = head; clt; ) {
        if (!clt->name[0]) {
            remove_client(&head, &prev, &clt);
        } else {
            prev = clt;
            clt = clt->next;
        }
    }
    *get_clients() = head;
    remove_user_same_name(&head);
}
