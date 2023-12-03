/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** load
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "load.h"

static FILE *create_save(void)
{
    FILE *file = fopen("save.txt", "w");

    SERVER_NO_SAVE_FOUND;
    fprintf(file, "%s", NO_DATA_PATTERN);
    return file;
}

void load_server(void)
{
    FILE *file = fopen("save.txt", "r");
    char line[MAX_BUF_LEN];

    !file ? file = create_save(), SERVER_LOAD : SERVER_LOAD;
    while (fgets(line, sizeof(line), file)) {
        if (!strcmp(line, NO_DATA_PATTERN)) {
            SERVER_NO_DATA;
            break;
        }
        !strcmp(line, CLIENTS_P) ? *get_clients() = load_clients(file) : 0;
        !strcmp(line, SUBSCRIPTIONS_P) ?
        *get_subscriptions() = load_subscriptions(file) : 0;
        !strcmp(line, DISCUSSIONS_P) ?
        *get_discussions() = load_discussions(file) : 0;
        !strcmp(line, TEAMS_P) ? *get_teams() = load_teams(file) : 0;
        !strcmp(line, CHANNELS_P) ? *get_channels() = load_channels(file) : 0;
        !strcmp(line, THREADS_P) ? *get_threads() = load_threads(file) : 0;
        !strcmp(line, REPLIES_P) ? *get_replies() = load_replies(file) : 0;
    }
    fclose(file);
}
