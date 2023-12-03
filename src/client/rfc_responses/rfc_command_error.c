/*
** EPITECH PROJECT, 2023
** rfc_command_error.c
** File description:
** rfc_command_error
*/

#include "rfc_client.h"

void call_client_error_cmd_not_found(char **infos, const char *response)
{
    (void)infos;
    printf(response);
}

void call_client_error_invalid_args_in_cmd(char **infos, const char *response)
{
    (void)infos;
    printf(response);
}
