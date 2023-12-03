/*
** EPITECH PROJECT, 2023
** load_replies.c
** File description:
** load_replies
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "load.h"

static reply_t *parse_reply_lines(FILE *file)
{
    reply_t *reply = malloc(sizeof(reply_t));
    char line[MAX_BUF_LEN];

    memset(reply, 0, sizeof(reply_t));
    fgets(line, sizeof(line), file);
    sscanf(line, UUID_PARSER, reply->uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, THREAD_UUID_PARSER, reply->thread_uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, CREATOR_UUID_PARSER, reply->creator_uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, BODY_PARSER, reply->body);
    reply->timestamp = parse_timestamp(file);
    reply->next = NULL;
    return reply;
}

reply_t *load_replies(FILE *file)
{
    reply_t *replies = NULL;
    reply_t *prev = NULL;
    char line[MAX_BUF_LEN];

    while (fgets(line, sizeof(line), file) && strcmp(line, END_OF_SECTION)) {
        reply_t *disc = parse_reply_lines(file);
        prev ? prev->next = disc : !prev ?
        replies = disc : 0;
        prev = disc;
    }
    return replies;
}
