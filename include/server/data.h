/*
** EPITECH PROJECT, 2023
** data.h
** File description:
** data
*/

#pragma once

#include "all_data.h"

void clean_server_data(void);
void create_client(int new_socket);
void create_discussion(client_t *clt);
void create_team(client_t *clt);
void create_channel(client_t *clt);
void create_thread(client_t *clt);
void create_reply(client_t *clt);
void create_subscription(client_t *clt);
void remove_subscription(client_t *clt);
bool is_subscribe(const char *uuid, const char *searched_uuid);
