/*
** EPITECH PROJECT, 2023
** utils_load.c
** File description:
** utils_load
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "load.h"

time_t parse_timestamp(FILE *file)
{
    char line[MAX_BUF_LEN];
    struct tm tm;

    fgets(line, sizeof(line), file);
    sscanf(line, "  Timestamp: %d-%d-%d %d:%d:%d",
    &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec);
    tm.tm_year -= 1900;
    tm.tm_mon -= 1;
    tm.tm_isdst = -1;
    return mktime(&tm);
}
