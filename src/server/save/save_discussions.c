/*
** EPITECH PROJECT, 2023
** save_discussions.c
** File description:
** save_discussions
*/

#include "save.h"

void save_discussions(discussion_t *disc, FILE *file)
{
    char time_str[MAX_BUF_LEN];

    if (disc) {
        fprintf(file, DISCUSSIONS_P);
        while (disc) {
            strftime(time_str, sizeof(time_str), TIMESTAMP_FORMAT,
            localtime(&disc->timestamp));
            fprintf(file, DISCUSSION_PARSER,
            disc->sender_uuid, disc->receiver_uuid, disc->body, time_str);
            disc = disc->next;
        }
    } else
        fprintf(file, NO_DISCUSSIONS_DATA);
    fprintf(file, END_OF_SECTION);
}
