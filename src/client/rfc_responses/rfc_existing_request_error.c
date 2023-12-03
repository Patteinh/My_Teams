/*
** EPITECH PROJECT, 2023
** rfc_existing_request_error.c
** File description:
** rfc_existing_request_error
*/

#include "rfc_client.h"

void call_client_error_already_exist(char **infos, const char *response)
{
    (void)infos;
    printf(response);
    client_error_already_exist();
}
