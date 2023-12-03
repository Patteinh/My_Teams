/*
** EPITECH PROJECT, 2023
** destroy_threads.c
** File description:
** destroy_threads
*/

#include <stdlib.h>
#include "destroy.h"

void free_threads(thread_t *thread)
{
    for (thread_t *tmp; thread; thread = tmp) {
        tmp = thread->next;
        free(thread);
    }
}
