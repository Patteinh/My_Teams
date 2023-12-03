/*
** EPITECH PROJECT, 2023
** load_discussions.c
** File description:
** load_discussions
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "load.h"

static discussion_t *parse_discussion_lines(FILE *file)
{
    discussion_t *discussion = malloc(sizeof(discussion_t));
    char line[MAX_BUF_LEN];

    memset(discussion, 0, sizeof(discussion_t));
    fgets(line, sizeof(line), file);
    sscanf(line, SENDER_UUID_PARSER, discussion->sender_uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, RECEIVER_UUID_PARSER, discussion->receiver_uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, MESSAGE_PARSER, discussion->body);
    discussion->timestamp = parse_timestamp(file);
    discussion->next = NULL;
    return discussion;
}

discussion_t *load_discussions(FILE *file)
{
    discussion_t *discussions = NULL;
    discussion_t *prev = NULL;
    char line[MAX_BUF_LEN];

    while (fgets(line, sizeof(line), file) && strcmp(line, END_OF_SECTION)) {
        discussion_t *disc = parse_discussion_lines(file);
        prev ? prev->next = disc : !prev ?
        discussions = disc : 0;
        prev = disc;
    }
    return discussions;
}
