/*
** EPITECH PROJECT, 2023
** init_client.c
** File description:
** init_client
*/

#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include "client.h"

void init_and_connect_client(client_t *clt, const char *ip, int port)
{
    clt->server_closed = false;
    CERROR((clt->sock.fd = socket(AF_INET, SOCK_STREAM, 0)) == FAIL, "socket");
    clt->sock.addr.sin_family = AF_INET;
    clt->sock.addr.sin_port = htons(port);
    CERROR(inet_pton(AF_INET, ip, &clt->sock.addr.sin_addr) <= 0, "inet_pton");
    CERROR(connect(clt->sock.fd, (struct sockaddr *)&clt->sock.addr,
    sizeof(clt->sock.addr)) == FAIL, "connect");
}
