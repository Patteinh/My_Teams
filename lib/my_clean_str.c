/*
** EPITECH PROJECT, 2023
** my_clean_str.c
** File description:
** remove unwanted letters from string
*/

#include <string.h>
#include <stdlib.h>
#include <stddef.h>

char *my_clean_str(const char *str, const char *delim)
{
    size_t len = 0;
    const char *s = str;
    char *new_str = NULL;
    char *t = NULL;

    for (; *s; s++)
        if (!strchr(delim, *s))
            len++;
    new_str = malloc(len + 1);
    if (!new_str)
        return NULL;
    t = new_str;
    for (; *str; str++)
        if (!strchr(delim, *str))
            *t++ = *str;
    *t = '\0';
    return new_str;
}
