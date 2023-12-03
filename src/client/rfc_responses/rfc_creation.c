/*
** EPITECH PROJECT, 2023
** rfc_creation.c
** File description:
** rfc_creation
*/

#include "rfc_client.h"

void call_client_print_team_created(char **infos, const char *response)
{
    printf(response);
    client_print_team_created(infos[0], infos[1], infos[2]);
}

void call_client_print_channel_created(char **infos, const char *response)
{
    printf(response);
    client_print_channel_created(infos[0], infos[1], infos[2]);
}

void call_client_print_thread_created(char **infos, const char *response)
{
    printf(response);
    client_print_thread_created(infos[0], infos[1],
    string_to_time(infos[2]), infos[3], infos[4]);
}

void call_client_print_reply_created(char **infos, const char *response)
{
    printf(response);
    client_print_reply_created(infos[0], infos[1],
    string_to_time(infos[2]), infos[3]);
}
