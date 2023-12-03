/*
** EPITECH PROJECT, 2023
** save.h
** File description:
** save
*/

#pragma once

#include "server.h"

#define ERROR_OPEN_SAVE ({ perror(OPEN_ERROR_MESS); })
#define SAVING_DATA ({ printf(SAVE_MESS); })
#define DISCUSSION_PARSER "Discussion:\n\tSender UUID: %s\n\
\tReceiver UUID: %s\n\tMessage: %s\n\tTimestamp: %s\n"
#define CHANNEL_PARSER "Channel:\n\tUUID: %s\n\tTeam UUID: %s\n\tName: \
%s\n\tDescription: %s\n"
#define CLIENT_PARSER "Client:\n\tUUID: %s\n\tUsername: %s\n"
#define SUBSCRIPTION_PARSER "Subscription:\n\tUser UUID: %s\n\tTeam UUID: %s\n"
#define THREAD_PARSER "Thread:\n\tUUID: %s\n\tChannel UUID: %s\n\t\
Creator UUID: %s\n\tTitle: %s\n\tBody: %s\n\tTimestamp: %s\n"
#define REPLY_PARSER "Reply:\n\tUUID: %s\n\tThread UUID: \
%s\n\tCreator UUID: %s\n\tBody: %s\n\tTimestamp: %s\n"
#define TEAM_PARSER "Team:\n\tUUID: %s\n\tName: %s\n\tDescription: %s\n"

static const char NO_TEAMS_DATA[] = "No teams data.\n";
static const char NO_THREADS_DATA[] = "No threads data.\n";
static const char NO_REPLIES_DATA[] = "No replies data.\n";
static const char NO_DISCUSSIONS_DATA[] = "No discussions data.\n";
static const char NO_SUBSCRIPTIONS_DATA[] = "No subscriptions data.\n";
static const char NO_CHANNELS_DATA[] = "No channels data.\n";
static const char OPEN_ERROR_MESS[] = "Error opening save.txt\n";
static const char SAVE_MESS[] = "Saving server data...\n";

int  save_clients(client_t *clt, FILE *file);
void save_discussions(discussion_t *disc, FILE *file);
void save_subscriptions(subscription_t *sub, FILE *file);
void save_replies(reply_t *reply, FILE *file);
void save_threads(thread_t *thread, FILE *file);
void save_teams(team_t *team, FILE *file);
void save_channels(channel_t *channel, FILE *file);
