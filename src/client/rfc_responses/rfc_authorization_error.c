/*
** EPITECH PROJECT, 2023
** rfc_authorization_error.c
** File description:
** rfc_authorization_error
*/

#include "rfc_client.h"

void call_client_error_unauthorized(char **infos, const char *response)
{
    (void)infos;
    printf(response);
    client_error_unauthorized();
}
