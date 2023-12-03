/*
** EPITECH PROJECT, 2023
** destroy_channels.c
** File description:
** destroy_channels
*/

#include <stdlib.h>
#include "destroy.h"

void free_channels(channel_t *channel)
{
    for (channel_t *tmp; channel; channel = tmp) {
        tmp = channel->next;
        free(channel);
    }
}
