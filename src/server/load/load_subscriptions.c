/*
** EPITECH PROJECT, 2023
** load_subscriptions.c
** File description:
** load_subscriptions
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "load.h"

subscription_t *parse_subscription_line(FILE *file)
{
    subscription_t *subscription = malloc(sizeof(subscription_t));
    char line[MAX_BUF_LEN];

    memset(subscription, 0, sizeof(subscription_t));
    fgets(line, sizeof(line), file);
    sscanf(line, USER_UUID_PARSER, subscription->user_uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, TEAM_UUID_PARSER, subscription->team_uuid);
    subscription->next = NULL;
    return subscription;
}

subscription_t *load_subscriptions(FILE *file)
{
    subscription_t *subscriptions = NULL;
    subscription_t *prev = NULL;
    char line[MAX_BUF_LEN];

    while (fgets(line, sizeof(line), file) && strcmp(line, END_OF_SECTION)) {
        subscription_t *subscription = parse_subscription_line(file);
        prev ? prev->next = subscription :
        !prev ? subscriptions = subscription : 0;
        prev = subscription;
    }
    return subscriptions;
}
