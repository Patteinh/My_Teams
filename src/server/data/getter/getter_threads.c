/*
** EPITECH PROJECT, 2023
** getter_threads.c
** File description:
** getter_threads
*/

#include "all_data.h"

thread_t **get_threads(void)
{
    static thread_t *head = NULL;
    return &head;
}
