/*
** EPITECH PROJECT, 2023
** init_server.c
** File description:
** init_server
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

static void init_and_bind_server_socket(socket_t *sock, const int port)
{
    sock->fd = socket(AF_INET, SOCK_STREAM, 0);
    CERROR(sock->fd == FAIL, "socket");
    sock->len = sizeof(struct sockaddr_in);
    memset(&sock->addr, 0, sock->len);
    sock->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    sock->addr.sin_port = htons(port);
    CERROR(bind(sock->fd, (const struct sockaddr *)
    &sock->addr, sock->len) == FAIL, "bind");
}

void init_server(server_t *srv, const int port)
{
    init_and_bind_server_socket(&srv->sock, port);
    CERROR(listen(srv->sock.fd, SOMAXCONN) == FAIL, "listen");
}
