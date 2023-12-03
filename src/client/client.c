/*
** EPITECH PROJECT, 2023
** client.c
** File description:
** client
*/

#include <stdlib.h>
#include "client.h"

static int client_loop(client_t *clt)
{
    reset_fd(clt);
    handle_events(clt);
    return LOOP;
}

int client(const char *ip, const char *port)
{
    client_t clt;
    init_and_connect_client(&clt, ip, atoi(port));
    while (client_loop(&clt) && !clt.server_closed);
    return (SUCCESS);
}
