/*
** EPITECH PROJECT, 2023
** getter_clients.c
** File description:
** getter_clients
*/

#include <string.h>
#include <stdlib.h>
#include "all_data.h"

client_t **get_clients(void)
{
    static client_t *head = NULL;
    return &head;
}
