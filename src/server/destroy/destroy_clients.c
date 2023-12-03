/*
** EPITECH PROJECT, 2023
** utils_destroy.c
** File description:
** utils_destroy
*/

#include <stdlib.h>
#include "destroy.h"

void free_clients(client_t *client)
{
    for (client_t *tmp; client; client = tmp) {
        tmp = client->next;
        free(client);
    }
}
