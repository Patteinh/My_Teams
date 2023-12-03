/*
** EPITECH PROJECT, 2023
** utils_cmd.c
** File description:
** utils_cmd
*/

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "command.h"

const char *skip_spaces(const char *p)
{
    for (; *p == ' '; p++);
    return p;
}

char *catch_cmd(const char *p, char **end_ptr)
{
    const char *start = p;
    size_t length;
    char *command;

    for (; *p != ' ' && *p; p++);
    length = p - start;
    command = malloc((length + 1) * sizeof(char));
    strncpy(command, start, length);
    command[length] = '\0';
    *end_ptr = (char *)p;
    return command;
}

char *catch_quoted_str(const char *p, char **end_ptr)
{
    const char *start = ++p;
    char *quoted_string;
    size_t length;

    for (; *p != '\"' && *p; p++);
    length = p - start;
    quoted_string = malloc((length + 1) * sizeof(char));
    strncpy(quoted_string, start, length);
    quoted_string[length] = '\0';
    *end_ptr = (char *)(*p == '\"' ? p + 1 : p);
    return quoted_string;
}

char **parse_cmd(const char input[MAX_BUF_LEN])
{
    int len = 2;
    char **array = malloc(len * sizeof(char *));
    int idx = 0;

    for (const char *p = input; *p; p = skip_spaces(p)) {
        if (idx >= len) {
            len *= 2;
            array = realloc(array, len * sizeof(char *));
        }
        if (idx != 0 && *p != '\"') {
            free(array);
            return NULL;
        }
        array[idx++] = *p == '\"' ?
        catch_quoted_str(p, (char **)&p) : catch_cmd(p, (char **)&p);
    }
    array = realloc(array, (idx + 1) * sizeof(char *));
    array[idx] = NULL;
    return array;
}

void my_send(const int socket, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    char message[MAX_BUF_LEN];

    if (!strchr(format, '%'))
        return SEND(socket, format);
    vsnprintf(message, sizeof(message), format, args);
    SEND(socket, message);
    va_end(args);
}
