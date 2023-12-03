/*
** EPITECH PROJECT, 2023
** save_channels.c
** File description:
** save_channels
*/

#include "save.h"

void save_channels(channel_t *channel, FILE *file)
{
    if (channel) {
        fprintf(file, CHANNELS_P);
        while (channel) {
            fprintf(file, CHANNEL_PARSER, channel->uuid, channel->team_uuid,
            channel->name, channel->description);
            channel = channel->next;
        }
    } else {
        fprintf(file, NO_CHANNELS_DATA);
    }
    fprintf(file, END_OF_SECTION);
}
