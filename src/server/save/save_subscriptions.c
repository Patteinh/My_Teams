/*
** EPITECH PROJECT, 2023
** save_subscriptions.c
** File description:
** save_subscriptions
*/

#include "save.h"

void save_subscriptions(subscription_t *sub, FILE *file)
{
    if (sub) {
        fprintf(file, SUBSCRIPTIONS_P);
        while (sub) {
            fprintf(file, SUBSCRIPTION_PARSER,
            sub->user_uuid, sub->team_uuid);
            sub = sub->next;
        }
    } else {
        fprintf(file, NO_SUBSCRIPTIONS_DATA);
    }
    fprintf(file, END_OF_SECTION);
}
