/*
** EPITECH PROJECT, 2023
** handle_events.c
** File description:
** handle_events
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "client.h"
#include "rfc_client.h"

static void receive_message(client_t *clt, const char buf[MAX_BUF_LEN])
{
    int idx = 0;

    if (buf[0] != START)
        return;
    get_infos(&clt->infos, buf);
    idx = what_code(&clt->infos);
    RFC[idx].code_function(clt->infos.array, RFC[idx].response);
    my_free_array(clt->infos.array);
}

static void read_server(client_t *clt)
{
    char buf[MAX_BUF_LEN];
    char tmp_buf[2] = {0};
    int bytes_read;
    int i;

    memset(buf, 0, MAX_BUF_LEN);
    for (i = 0; i < MAX_BUF_LEN - 1; i++) {
        bytes_read = read(clt->sock.fd, tmp_buf, 1);
        CERROR(bytes_read == FAIL, "read");
        if (bytes_read == 0) {
            close_server(clt);
            break;
        }
        if (tmp_buf[0] == '\n')
            break;
        buf[i] = tmp_buf[0];
    }
    i > 0 ? buf[i] = '\0', receive_message(clt, buf) : 0;
}

static void read_client(client_t *clt)
{
    char buf[MAX_BUF_LEN];

    if (fgets(buf, sizeof(buf), stdin) && strcmp(buf, NEW_LINE))
        SEND(clt->sock.fd, buf);
}

void handle_events(client_t *clt)
{
    int rfds = select(clt->sock.fd + 1, &clt->readfds, NULL, NULL, NULL);

    if (rfds < 0)
        return;
    if (FD_ISSET(STDIN_FILENO, &clt->readfds))
        read_client(clt);
    if (FD_ISSET(clt->sock.fd, &clt->readfds))
        read_server(clt);
}
