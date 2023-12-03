/*
** EPITECH PROJECT, 2023
** rfc_utils.c
** File description:
** rfc_utils
*/

#include <time.h>
#include <string.h>
#include "rfc_client.h"

time_t string_to_time(const char *timestamp_str)
{
    struct tm tm;
    time_t timestamp;

    memset(&tm, 0, sizeof(struct tm));
    sscanf(timestamp_str, TIMESTAMP_FORMAT,
    &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec);
    tm.tm_year -= 1900;
    tm.tm_mon -= 1;
    tm.tm_isdst = -1;
    timestamp = mktime(&tm);
    return timestamp;
}

int what_code(receive_infos_t *infos)
{
    for (int i = 0; RFC[i].code; i++)
        if (infos->rfc_code == RFC[i].code)
            return i;
    return ERROR;
}
