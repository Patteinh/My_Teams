/*
** EPITECH PROJECT, 2023
** save_clients.c
** File description:
** save_clients
*/

#include "save.h"

int save_clients(client_t *clt, FILE *file)
{
    if (clt) {
        fprintf(file, CLIENTS_P);
        while (clt) {
            fprintf(file, CLIENT_PARSER,
                clt->uuid, clt->name);
            clt = clt->next;
        }
    } else {
        fprintf(file, NO_DATA_PATTERN);
        return FAIL;
    }
    fprintf(file, END_OF_SECTION);
    return SUCCESS;
}
