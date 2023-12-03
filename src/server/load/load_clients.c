/*
** EPITECH PROJECT, 2023
** load_clients.c
** File description:
** load_clients
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "load.h"

static client_t *parse_client_lines(FILE *file)
{
    client_t *client = malloc(sizeof(client_t));
    char line[MAX_BUF_LEN];

    memset(client, 0, sizeof(client_t));
    fgets(line, sizeof(line), file);
    sscanf(line, UUID_PARSER, client->uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, USERNAME_PARSER, client->name);
    client->next = NULL;
    return client;
}

client_t *load_clients(FILE *file)
{
    client_t *clients = NULL;
    client_t *prev = NULL;
    char line[MAX_BUF_LEN];

    while (fgets(line, sizeof(line), file) && strcmp(line, END_OF_SECTION)) {
        client_t *client = parse_client_lines(file);
        prev ? prev->next = client : !prev ? clients = client : 0;
        prev = client;
        server_event_user_loaded(client->uuid, client->name);
    }
    return clients;
}
