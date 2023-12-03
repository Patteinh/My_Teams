/*
** EPITECH PROJECT, 2023
** command.h
** File description:
** command
*/

#pragma once

#include "server.h"
#include "rfc_server.h"

void help_teams(client_t *clt);
void login_teams(client_t *clt);
void logout_teams(client_t *clt);
void users_teams(client_t *clt);
void user_teams(client_t *clt);
void send_teams(client_t *clt);
void messages_teams(client_t *clt);
void subscribe_teams(client_t *clt);
void subscribed_teams(client_t *clt);
void unsubscribe_teams(client_t *clt);
void use_teams(client_t *clt);
void create_teams(client_t *clt);
void list_teams(client_t *clt);
void info_teams(client_t *clt);

static const size_t NOT_FOUND = 404;

typedef struct command_s {
    const bool is_log;
    const char *cmd;
    void (*const cmd_function)(client_t *);
    const size_t *nb_args;
} command_t;

static const size_t args_help[] = {0, NOT_FOUND};
static const size_t args_login[] = {1, NOT_FOUND};
static const size_t args_logout[] = {0, NOT_FOUND};
static const size_t args_users[] = {0, NOT_FOUND};
static const size_t args_user[] = {1, NOT_FOUND};
static const size_t args_send[] = {2, NOT_FOUND};
static const size_t args_messages[] = {1, NOT_FOUND};
static const size_t args_subscribe[] = {1, NOT_FOUND};
static const size_t args_unsubscribe[] = {1, NOT_FOUND};
static const size_t args_subscribed[] = {0, 1, NOT_FOUND};
static const size_t args_use[] = {0, 1, 2, 3, NOT_FOUND};
static const size_t args_create[] = {1, 2, NOT_FOUND};
static const size_t args_list[] = {0, NOT_FOUND};
static const size_t args_info[] = {0, NOT_FOUND};
static const size_t args_none[] = {NOT_FOUND};

static const command_t ALLCMD[] =
{
    {false, "/help", help_teams, args_help},
    {false, "/login", login_teams, args_login},
    {true, "/logout", logout_teams, args_logout},
    {true, "/users", users_teams, args_users},
    {true, "/user", user_teams, args_user},
    {true, "/send", send_teams, args_send},
    {true, "/messages", messages_teams, args_messages},
    {true, "/subscribe", subscribe_teams, args_subscribe},
    {true, "/unsubscribe", unsubscribe_teams, args_unsubscribe},
    {true, "/subscribed", subscribed_teams, args_subscribed},
    {true, "/use", use_teams, args_use},
    {true, "/create", create_teams, args_create},
    {true, "/list", list_teams, args_list},
    {true, "/info", info_teams, args_info},
    {true, NULL, NULL, args_none}
};

void my_send(const int socket, const char *format, ...);
client_t *find_client_uuid(const char *uuid);
char **parse_cmd(const char input[MAX_BUF_LEN]);
