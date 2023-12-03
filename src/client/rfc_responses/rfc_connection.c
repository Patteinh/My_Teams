/*
** EPITECH PROJECT, 2023
** rfc_connection.c
** File description:
** rfc_connection
*/

#include "rfc_client.h"

void call_client_event_logged_in(char **infos, const char *response)
{
    printf(response);
    client_event_logged_in(infos[0], infos[1]);
}

void call_client_event_logged_out(char **infos, const char *response)
{
    printf(response);
    client_event_logged_out(infos[0], infos[1]);
}
