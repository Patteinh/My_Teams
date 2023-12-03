/*
** EPITECH PROJECT, 2023
** utils_server.c
** File description:
** utils_server
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

char *time_to_string(time_t timestamp)
{
    char *time_str;

    time_str = (char *) malloc(64 * sizeof(char));
    if (!time_str)
        return NULL;
    strftime(time_str, 64, TIMESTAMP_FORMAT, localtime(&timestamp));
    return time_str;
}

void reset_fd(server_t *srv)
{
    FD_ZERO(&srv->readfds);
    FD_SET(srv->sock.fd, &srv->readfds);
    srv->max_fd = srv->sock.fd;
    for (client_t *tmp = *get_clients(); tmp; tmp = tmp->next)
        if (tmp->online && tmp->socket) {
            FD_SET(tmp->socket, &srv->readfds);
            tmp->socket > srv->max_fd ? srv->max_fd = tmp->socket : 0;
        }
}
