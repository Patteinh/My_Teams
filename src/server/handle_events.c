/*
** EPITECH PROJECT, 2023
** handle_events.c
** File description:
** handle_events
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"
#include "data.h"

static void read_cmd(client_t *clt, char buf[MAX_BUF_LEN])
{
    char *cleaned_buf = my_clean_str(buf, USLESS_DELIMITERS);
    handle_cmd(clt, cleaned_buf);
    my_free_array(clt->cmd);
    free(cleaned_buf);
}

static void read_client(client_t *clt)
{
    char buf[MAX_BUF_LEN];
    int bytes_read = 0;

    memset(buf, 0, MAX_BUF_LEN);
    CERROR((bytes_read = read(clt->socket, buf, MAX_BUF_LEN)) == FAIL, "read");
    bytes_read == 0 ? disconnect_client(clt) : read_cmd(clt, buf);
}

static void handle_new_client(server_t *srv)
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr_in);
    int sock = accept(srv->sock.fd, (struct sockaddr *)&addr, &len);

    CERROR(sock == FAIL, "accept");
    create_client(sock);
    printf("User connect with socket [%d].\n", sock);
}

void handle_events(server_t *srv)
{
    if (FD_ISSET(srv->sock.fd, &srv->readfds))
        handle_new_client(srv);
    for (client_t *tmp = *get_clients(); tmp; tmp = tmp->next)
        if (tmp->online && FD_ISSET(tmp->socket, &srv->readfds))
            read_client(tmp);
}
