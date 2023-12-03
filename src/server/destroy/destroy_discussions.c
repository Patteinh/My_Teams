/*
** EPITECH PROJECT, 2023
** destroy_discussions.c
** File description:
** destroy_discussions
*/

#include <stdlib.h>
#include "destroy.h"

void free_discussions(discussion_t *discussions)
{
    for (discussion_t *tmp; discussions; discussions = tmp) {
        tmp = discussions->next;
        free(discussions);
    }
}
