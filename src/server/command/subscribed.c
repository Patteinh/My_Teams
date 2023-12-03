/*
** EPITECH PROJECT, 2023
** subscribed.c
** File description:
** subscribed
*/

#include <string.h>
#include "command.h"

static void print_list_subscriptions(client_t *clt)
{
    size_t nb_sub = 0;

    for (subscription_t *tmp = *get_subscriptions(); tmp; tmp = tmp->next)
        if (!strcmp(clt->uuid, tmp->user_uuid)) {
            my_send(clt->socket, RFC_350.response, tmp->team_uuid,
            find_team_uuid(tmp->team_uuid)->name,
            find_team_uuid(tmp->team_uuid)->description);
            nb_sub++;
        }
    nb_sub == 0 ? my_send(clt->socket, RFC_455.response) : 0;
}

static void print_list_clients_subscribed_to_team(client_t *clt)
{
    team_t *team = find_team_uuid(clt->cmd[1]);
    size_t nb_clt_sub = 0;

    if (!team)
        return my_send(clt->socket, RFC_410.response, clt->cmd[1]);
    for (subscription_t *tmp = *get_subscriptions(); tmp; tmp = tmp->next)
        if (!strcmp(team->uuid, tmp->team_uuid)) {
            my_send(clt->socket, RFC_340.response, tmp->user_uuid,
            find_client_uuid(tmp->user_uuid)->name,
            find_client_uuid(tmp->user_uuid)->is_log ? "1" : "0");
            nb_clt_sub++;
        }
    nb_clt_sub == 0 ? my_send(clt->socket, RFC_495.response) : 0;
}

void subscribed_teams(client_t *clt)
{
    (my_arraylen(clt->cmd) - 1) == 0 ?
    print_list_subscriptions(clt) : print_list_clients_subscribed_to_team(clt);
}
