/*
** EPITECH PROJECT, 2023
** load.h
** File description:
** load
*/

#pragma once

#include "server.h"

#define SERVER_LOAD ({ printf(LOAD_MESS); })
#define SERVER_NO_DATA ({ printf(NO_DATA_MESS); })
#define SERVER_NO_SAVE_FOUND ({ printf(NO_SAVE_MESS); })
#define UUID_PARSER "\tUUID: %[^\n]"
#define MESSAGE_PARSER "\tMessage: %[^\n]"
#define SENDER_UUID_PARSER "\tSender UUID: %[^\n]"
#define RECEIVER_UUID_PARSER "\tReceiver UUID: %[^\n]"
#define USER_UUID_PARSER "\tUser UUID: %[^,\n]"
#define TEAM_UUID_PARSER "\tTeam UUID: %[^,\n]"
#define CHANNEL_UUID_PARSER "\tChannel UUID: %[^\n]"
#define CREATOR_UUID_PARSER "\tCreator UUID: %[^\n]"
#define THREAD_UUID_PARSER "\tThread UUID: %[^\n]"
#define USERNAME_PARSER "\tUsername: %[^,\n]"
#define TITLE_PARSER "\tTitle: %[^\n]"
#define BODY_PARSER "\tBody: %[^\n]"
#define DESCRIPTION_PARSER "\tDescription: %[^,\n]"
#define NAME_PARSER "\tName: %[^,\n]"

static const char LOAD_MESS[] = "Loading server data...\n";
static const char NO_DATA_MESS[] = "No data to load.\n";
static const char NO_SAVE_MESS[] = "Save Teams not found, new save created.\n";

client_t *load_clients(FILE *file);
discussion_t *load_discussions(FILE *file);
subscription_t *load_subscriptions(FILE *file);
team_t *load_teams(FILE *file);
channel_t *load_channels(FILE *file);
thread_t *load_threads(FILE *file);
reply_t *load_replies(FILE *file);
time_t parse_timestamp(FILE *file);
