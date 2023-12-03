/*
** EPITECH PROJECT, 2023
** client.h
** File description:
** client.h
*/

#pragma once

#include <logging_client.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <stdbool.h>
#include "my.h"

#define MAX_BUF_LEN 1024
#define CERROR(iserror, e) ((iserror) ? (perror(e), exit(ERROR)) : 0)
#define SERVER_CLOSE ({ printf(SERVER_CLOSE_MESS); })
#define HELP ({ printf(USAGE_CLI); SUCCESS; })
#define IS_NUMBER(str) ({ \
    int is_number = 1; \
    for (size_t i = 0; str[i]; i++) \
        if (!isdigit(str[i])) { \
            is_number = 0; \
            break; \
        } \
    is_number; \
})

static const int FAIL = -1;
static const int LOOP = 1;
static const int EXIT_LOOP = 0;
static const char START = '[';
static const char END = ']';
static const char NEW_LINE [] = "\n";
static const char SEP_INFOS[] = "[]|";
static const char SERVER_CLOSE_MESS[] = "Server closed the connection.\n";
static const char USAGE_CLI[] = "USAGE: ./myteams_cli ip port\n"
    "\tip\tis the server ip address on which the server socket listens\n"
    "\tport\tis the port number on which the server socket listens\n";

typedef struct socket_s {
    int fd;
    socklen_t len;
    struct sockaddr_in addr;
} socket_t;

typedef struct receive_infos_s {
    char **array;
    int rfc_code;
} receive_infos_t;

typedef struct client_s {
    socket_t sock;
    fd_set readfds;
    receive_infos_t infos;
    bool server_closed;
} client_t;

int  check_errors(int ac, char *av[]);
int  client(const char *ip, const char *port);
void init_and_connect_client(client_t *clt, const char *ip, int port);
void get_infos(receive_infos_t *infos, const char buf[MAX_BUF_LEN]);
void handle_events(client_t *clt);
void close_server(client_t *clt);
void reset_fd(client_t *clt);
