/*
** EPITECH PROJECT, 2023
** save_threads.c
** File description:
** save_threads
*/

#include "save.h"

void save_threads(thread_t *thread, FILE *file)
{
    char time_str[MAX_BUF_LEN];

    if (thread) {
        fprintf(file, THREADS_P);
        while (thread) {
            strftime(time_str, sizeof(time_str), TIMESTAMP_FORMAT,
            localtime(&thread->timestamp));
            fprintf(file, THREAD_PARSER,
            thread->uuid, thread->channel_uuid, thread->creator_uuid,
            thread->title, thread->body, time_str);
            thread = thread->next;
        }
    } else {
        fprintf(file, NO_THREADS_DATA);
    }
    fprintf(file, END_OF_SECTION);
}
