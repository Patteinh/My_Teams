/*
** EPITECH PROJECT, 2023
** rfc_individual_info.c
** File description:
** rfc_individual_info
*/

#include <stdlib.h>
#include "rfc_client.h"

void call_client_print_user(char **infos, const char *response)
{
    printf(response);
    client_print_user(infos[0], infos[1], atoi(infos[2]));
}

void call_client_print_team(char **infos, const char *response)
{
    printf(response);
    client_print_team(infos[0], infos[1], infos[2]);
}

void call_client_print_channel(char **infos, const char *response)
{
    printf(response);
    client_print_channel(infos[0], infos[1], infos[2]);
}

void call_client_print_thread(char **infos, const char *response)
{
    printf(response);
    client_print_thread(infos[0], infos[1],
    string_to_time(infos[2]), infos[3], infos[4]);
}

void call_client_private_message_print_messages
(char **infos, const char *response)
{
    printf(response);
    client_private_message_print_messages(infos[0],
    string_to_time(infos[1]), infos[2]);
}
