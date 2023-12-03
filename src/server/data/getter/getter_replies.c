/*
** EPITECH PROJECT, 2023
** getter_replies.c
** File description:
** getter_replies
*/

#include "all_data.h"

reply_t **get_replies(void)
{
    static reply_t *head = NULL;
    return &head;
}
