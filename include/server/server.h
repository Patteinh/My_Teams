/*
** EPITECH PROJECT, 2023
** server.h
** File description:
** server
*/

#pragma once

#include <netinet/in.h>
#include <sys/select.h>
#include <stdio.h>
#include "logging_server.h"
#include "all_data.h"
#include "tools.h"
#include "destroy.h"
#include "my.h"

#define TIMESTAMP_FORMAT "%Y-%m-%d %H:%M:%S"
#define CERROR(iserror, e) (iserror ? perror(e), exit(ERROR) : 0)
#define HELP ({ printf(USAGE_SERVER); SUCCESS; })
#define TIMEOUT ({ printf(TIMEOUT_MESS); EXIT_LOOP; })
#define HANDLE_EVENTS ({ handle_events(srv); LOOP; })
#define SERVER_START(socket) ({ printf(START_MESS, socket); })
#define SERVER_DISCONNECTION(socket) ({ printf(DISCONNECTION_MESS, socket); })
#define IS_NUMBER(str) ({ \
    int is_number = 1; \
    for (int i = 0; str[i]; i++) \
        if (!isdigit(str[i])) { \
            is_number = 0; \
            break; \
        } \
    is_number; \
})

static const int FAIL = -1;
static const int LOOP = 1;
static const int EXIT_LOOP = 0;
static const int TIMEOUT_TIME = 60;
static const char EMPTY[] = "";
static const char HELP_CMD[] = "/help";
static const char DELIMITER[] = " ";
static const char USLESS_DELIMITERS[] = "\r\n\t";
static const char TIMEOUT_MESS[] = "Timeout server close.\r\n";
static const char USAGE_SERVER[] = "USAGE: ./myteams_server port\n\n"
"\tport is the port number on which the server socket listens.\n";
static const char DISCONNECTION_MESS[] = "User disconnect with socket [%d].\n";
static const char START_MESS[] = "Server created and "
"start with socket [%d].\n";

typedef struct socket_s {
    int fd;
    socklen_t len;
    struct sockaddr_in addr;
} socket_t;

typedef struct server_s {
    socket_t sock;
    fd_set readfds;
    fd_set writefds;
    int max_fd;
} server_t;

void reset_fd(server_t *srv);
void disconnect_client(client_t *clt);
void remove_client(client_t *clt_to_remove);
int  check_errors(int ac, char *av[]);
int  server(const char *port);
void init_server(server_t *srv, const int port);
void handle_events(server_t *srv);
void handle_cmd(client_t *clt, const char cleaned_buf[MAX_BUF_LEN]);
void save_server(void);
void load_server(void);
