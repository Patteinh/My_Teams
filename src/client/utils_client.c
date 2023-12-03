/*
** EPITECH PROJECT, 2023
** utils_client.c
** File description:
** utils_client
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "client.h"

static void get_array(char ***array, const char *start, const char *end)
{
    char *tok;
    char *tmp;
    int i = 0;
    int j = 0;

    char *tmp2 = strndup(start, end - start + 1);
    tmp = strdup(tmp2);
    for (tok = strtok(tmp, SEP_INFOS); tok; tok = strtok(NULL, SEP_INFOS))
        i++;
    free(tmp);
    *array = (char **)malloc(sizeof(char *) * (i + 1));
    tmp = strdup(tmp2);
    for (tok = strtok(tmp, SEP_INFOS); tok; tok = strtok(NULL, SEP_INFOS))
        (*array)[j++] = strdup(tok);
    (*array)[i] = NULL;
    free(tmp);
    free(tmp2);
}

void get_infos(receive_infos_t *infos, const char buf[MAX_BUF_LEN])
{
    char *start = strrchr(buf, START);
    char *end = strrchr(buf, END);

    sscanf(buf, "[%d]", &infos->rfc_code);
    if (start && start != buf)
        get_array(&infos->array, start, end);
    else
        infos->array = NULL;
}

void close_server(client_t *clt)
{
    close(clt->sock.fd);
    clt->server_closed = true;
    SERVER_CLOSE;
}

void reset_fd(client_t *clt)
{
    FD_ZERO(&clt->readfds);
    FD_SET(clt->sock.fd, &clt->readfds);
    FD_SET(STDIN_FILENO, &clt->readfds);
}
