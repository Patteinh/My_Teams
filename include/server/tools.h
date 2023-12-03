/*
** EPITECH PROJECT, 2023
** tools.h
** File description:
** tools
*/

#pragma once

#include "server.h"

client_t *find_client_uuid(const char *uuid);
client_t *find_client_name(const char *name);
team_t *find_team_uuid(const char *uuid);
team_t *find_team_name(const char *name);
channel_t *find_channel_uuid(const char *uuid);
channel_t *find_channel_name(const char *name);
thread_t *find_thread_uuid(const char *uuid);
thread_t *find_thread_name(const char *name);
reply_t *find_reply_uuid(const char *uuid);
char *time_to_string(time_t timestamp);
