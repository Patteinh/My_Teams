/*
** EPITECH PROJECT, 2023
** destroy_replies.c
** File description:
** destroy_replies
*/

#include <stdlib.h>
#include "destroy.h"

void free_replies(reply_t *reply)
{
    for (reply_t *tmp; reply; reply = tmp) {
        tmp = reply->next;
        free(reply);
    }
}
