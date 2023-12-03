/*
** EPITECH PROJECT, 2023
** save_server.c
** File description:
** save_server
*/

#include <stdio.h>
#include <unistd.h>
#include "save.h"

static FILE *use_file(void)
{
    FILE *file;

    if (access("save.txt", F_OK) != FAIL)
        file = fopen("save.txt", "r+");
    else
        file = fopen("save.txt", "w");
    return file;
}

void save_server(void)
{
    FILE *file = use_file();

    if (!file)
        return ERROR_OPEN_SAVE;
    if (ftruncate(fileno(file), 0) == FAIL)
        return (void)fclose(file);
    if (save_clients(*get_clients(), file) == FAIL) {
        fclose(file);
        return;
    }
    save_subscriptions(*get_subscriptions(), file);
    save_discussions(*get_discussions(), file);
    save_teams(*get_teams(), file);
    save_channels(*get_channels(), file);
    save_threads(*get_threads(), file);
    save_replies(*get_replies(), file);
    fprintf(file, END_OF_DATA);
    fclose(file);
}
