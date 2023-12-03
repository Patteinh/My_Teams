/*
** EPITECH PROJECT, 2023
** rfc_subscription.c
** File description:
** rfc_subscription
*/

#include "rfc_client.h"

void call_client_print_subscribed(char **infos, const char *response)
{
    printf(response);
    client_print_subscribed(infos[0], infos[1]);
}

void call_client_print_unsubscribed(char **infos, const char *response)
{
    printf(response);
    client_print_unsubscribed(infos[0], infos[1]);
}

void call_client_no_teams_subscriptions_found
(char **infos, const char *response)
{
    (void)infos;
    printf(response);
}

void call_client_no_clients_subscriptions_to_team_found
(char **infos, const char *response)
{
    (void)infos;
    printf(response);
}
