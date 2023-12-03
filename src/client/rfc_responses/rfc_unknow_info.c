/*
** EPITECH PROJECT, 2023
** rfc_unknow_info.c
** File description:
** rfc_unknow_info
*/

#include "rfc_client.h"

void call_client_error_unknown_user(char **infos, const char *response)
{
    printf(response);
    client_error_unknown_user(infos[0]);
}

void call_client_error_unknown_team(char **infos, const char *response)
{
    printf(response);
    client_error_unknown_team(infos[0]);
}

void call_client_error_unknown_channel(char **infos, const char *response)
{
    printf(response);
    client_error_unknown_channel(infos[0]);
}

void call_client_error_unknown_thread(char **infos, const char *response)
{
    printf(response);
    client_error_unknown_thread(infos[0]);
}
