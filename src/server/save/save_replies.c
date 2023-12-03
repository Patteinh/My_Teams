/*
** EPITECH PROJECT, 2023
** save_replies.c
** File description:
** save_replies
*/

#include "save.h"

void save_replies(reply_t *reply, FILE *file)
{
    char time_str[MAX_BUF_LEN];

    if (reply) {
        fprintf(file, REPLIES_P);
        while (reply) {
            strftime(time_str, sizeof(time_str), TIMESTAMP_FORMAT,
            localtime(&reply->timestamp));
            fprintf(file, REPLY_PARSER,
            reply->uuid, reply->thread_uuid, reply->creator_uuid,
            reply->body, time_str);
            reply = reply->next;
        }
    } else {
        fprintf(file, NO_REPLIES_DATA);
    }
    fprintf(file, END_OF_SECTION);
}
