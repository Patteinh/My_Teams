/*
** EPITECH PROJECT, 2023
** desroy.h
** File description:
** destroy
*/

#pragma once

#include "all_data.h"

void destroy_server(void);
void free_subscriptions(subscription_t *subscription);
void free_discussions(discussion_t *discussions);
void free_clients(client_t *clients);
void free_teams(team_t *team);
void free_channels(channel_t *channel);
void free_threads(thread_t *thread);
void free_replies(reply_t *reply);
