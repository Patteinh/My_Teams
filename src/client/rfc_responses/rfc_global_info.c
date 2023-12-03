/*
** EPITECH PROJECT, 2023
** rfc_global_info.c
** File description:
** rfc_global_info
*/

#include <stdlib.h>
#include "rfc_client.h"

void call_client_print_users(char **infos, const char *response)
{
    printf(response);
    client_print_users(infos[0], infos[1], atoi(infos[2]));
}

void call_client_print_teams(char **infos, const char *response)
{
    printf(response);
    client_print_teams(infos[0], infos[1], infos[2]);
}

void call_client_team_print_channels(char **infos, const char *response)
{
    printf(response);
    client_team_print_channels(infos[0], infos[1], infos[2]);
}

void call_client_channel_print_threads(char **infos, const char *response)
{
    printf(response);
    client_channel_print_threads(infos[0], infos[1],
    string_to_time(infos[2]), infos[3], infos[4]);
}

void call_client_thread_print_replies(char **infos, const char *response)
{
    printf(response);
    client_thread_print_replies(infos[0], infos[1],
    string_to_time(infos[2]), infos[3]);
}
