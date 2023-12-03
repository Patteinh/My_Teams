/*
** EPITECH PROJECT, 2023
** getter_subscriptions.c
** File description:
** getter_subscriptions
*/

#include "all_data.h"

subscription_t **get_subscriptions(void)
{
    static subscription_t *head = NULL;
    return &head;
}
