/*
** EPITECH PROJECT, 2023
** load_threads.c
** File description:
** load_threads
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "load.h"

static thread_t *parse_thread_lines(FILE *file)
{
    thread_t *thread = malloc(sizeof(thread_t));
    char line[MAX_BUF_LEN];

    memset(thread, 0, sizeof(thread_t));
    fgets(line, sizeof(line), file);
    sscanf(line, UUID_PARSER, thread->uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, CHANNEL_UUID_PARSER, thread->channel_uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, CREATOR_UUID_PARSER, thread->creator_uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, TITLE_PARSER, thread->title);
    fgets(line, sizeof(line), file);
    sscanf(line, BODY_PARSER, thread->body);
    thread->timestamp = parse_timestamp(file);
    thread->next = NULL;
    return thread;
}

thread_t *load_threads(FILE *file)
{
    thread_t *threads = NULL;
    thread_t *prev = NULL;
    char line[MAX_BUF_LEN];

    while (fgets(line, sizeof(line), file) && strcmp(line, END_OF_SECTION)) {
        thread_t *disc = parse_thread_lines(file);
        prev ? prev->next = disc : !prev ?
        threads = disc : 0;
        prev = disc;
    }
    return threads;
}
