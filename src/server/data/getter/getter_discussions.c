/*
** EPITECH PROJECT, 2023
** getter_discussions.c
** File description:
** getter_discussions
*/

#include "all_data.h"

discussion_t **get_discussions(void)
{
    static discussion_t *head = NULL;
    return &head;
}
