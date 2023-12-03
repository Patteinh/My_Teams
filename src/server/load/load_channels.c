/*
** EPITECH PROJECT, 2023
** load_channels.c
** File description:
** load_channels
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "load.h"

static channel_t *parse_channel_lines(FILE *file)
{
    channel_t *channel = malloc(sizeof(channel_t));
    char line[MAX_BUF_LEN];

    memset(channel, 0, sizeof(channel_t));
    fgets(line, sizeof(line), file);
    sscanf(line, UUID_PARSER, channel->uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, TEAM_UUID_PARSER, channel->team_uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, NAME_PARSER, channel->name);
    fgets(line, sizeof(line), file);
    sscanf(line, DESCRIPTION_PARSER, channel->description);
    channel->next = NULL;
    return channel;
}

channel_t *load_channels(FILE *file)
{
    channel_t *channels = NULL;
    channel_t *prev = NULL;
    char line[MAX_BUF_LEN];

    while (fgets(line, sizeof(line), file) && strcmp(line, END_OF_SECTION)) {
        channel_t *channel = parse_channel_lines(file);
        prev ? prev->next = channel : !prev ? channels = channel : 0;
        prev = channel;
    }
    return channels;
}
