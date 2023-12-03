/*
** EPITECH PROJECT, 2023
** getter_channels.c
** File description:
** getter_channels
*/

#include "all_data.h"

channel_t **get_channels(void)
{
    static channel_t *head = NULL;
    return &head;
}
