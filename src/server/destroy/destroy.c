/*
** EPITECH PROJECT, 2023
** destroy.c
** File description:
** destroy
*/

#include "destroy.h"

void destroy_server(void)
{
    free_clients(*get_clients());
    free_teams(*get_teams());
    free_channels(*get_channels());
    free_threads(*get_threads());
    free_replies(*get_replies());
    free_discussions(*get_discussions());
    free_subscriptions(*get_subscriptions());
}
