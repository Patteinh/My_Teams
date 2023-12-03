/*
** EPITECH PROJECT, 2023
** unsubscribe.c
** File description:
** unsubscribe
*/

#include <string.h>
#include "command.h"
#include "data.h"

static bool subscription_not_exist(client_t *clt)
{
    for (subscription_t *tmp = *get_subscriptions(); tmp; tmp = tmp->next)
        if (!strcmp(clt->uuid, tmp->user_uuid) &&
        (!strcmp(clt->cmd[1], tmp->team_uuid)))
            return false;
    return true;
}

void unsubscribe_teams(client_t *clt)
{
    team_t *team = find_team_uuid(clt->cmd[1]);

    if (!team)
        return my_send(clt->socket, RFC_410.response, clt->cmd[1]);
    if (subscription_not_exist(clt) == true)
        return my_send(clt->socket, RFC_410.response, clt->cmd[1]);
    remove_subscription(clt);
    server_event_user_unsubscribed(team->uuid, clt->uuid);
    my_send(clt->socket, RFC_240.response, clt->uuid, team->uuid);
}
