/*
** EPITECH PROJECT, 2023
** destroy_subscriptions.c
** File description:
** destroy_subscriptions
*/

#include <stdlib.h>
#include "destroy.h"

void free_subscriptions(subscription_t *subscription)
{
    for (subscription_t *tmp; subscription; subscription = tmp) {
        tmp = subscription->next;
        free(subscription);
    }
}
