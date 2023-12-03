/*
** EPITECH PROJECT, 2023
** server.c
** File description:
** server
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"
#include "data.h"

static int server_loop(server_t *srv)
{
    struct timeval timeout = {TIMEOUT_TIME, 0};
    int select_val;

    reset_fd(srv);
    CERROR((select_val = select(srv->max_fd + 1, &srv->readfds,
    NULL, NULL, &timeout)) == FAIL, "select");
    return select_val == 0 ? TIMEOUT : HANDLE_EVENTS;
}

int server(const char *port)
{
    server_t srv;

    init_server(&srv, atoi(port));
    load_server();
    SERVER_START(srv.sock.fd);
    while (server_loop(&srv));
    clean_server_data();
    save_server();
    destroy_server();
    return SUCCESS;
}
