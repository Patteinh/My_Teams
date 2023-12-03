/*
** EPITECH PROJECT, 2023
** handle_subscriptions.c
** File description:
** handle_subscriptions
*/

#include <string.h>
#include <stdlib.h>
#include "data.h"

static void set_data_new_subscription(subscription_t *new, client_t *clt)
{
    strcpy(new->team_uuid, clt->cmd[1]);
    strcpy(new->user_uuid, clt->uuid);
    new->next = NULL;
}

static void add_subscription_to_others(subscription_t *new)
{
    get_subscriptions() ? new->next = *get_subscriptions() : 0;
    *get_subscriptions() = new;
}

void remove_subscription(client_t *clt)
{
    subscription_t **current_sub = get_subscriptions();

    while (*current_sub) {
        if (!strcmp((*current_sub)->user_uuid, clt->uuid) &&
            !strcmp((*current_sub)->team_uuid, clt->cmd[1])) {
            subscription_t *to_remove = *current_sub;
            *current_sub = (*current_sub)->next;
            free(to_remove);
            return;
        }
        current_sub = &(*current_sub)->next;
    }
}

void create_subscription(client_t *clt)
{
    subscription_t *new = malloc(sizeof(*new));

    set_data_new_subscription(new, clt);
    add_subscription_to_others(new);
}
