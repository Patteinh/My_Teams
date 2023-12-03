/*
** EPITECH PROJECT, 2023
** my_str_to_array.c
** File description:
** str to array with delim
*/

#include <string.h>
#include <stdlib.h>
#include <stddef.h>

char **my_str_to_array(const char *str, const char *delim)
{
    char **array = NULL;
    int nb_words = 0;

    for (int i = 0; str[i];) {
        for (; strchr(delim, str[i]) && str[i]; i++);
        if (!str[i])
            break;
        nb_words++;
        int j = i;
        for (; !strchr(delim, str[j]) && str[j]; j++);
        array = realloc(array, sizeof(*array) * (nb_words + 1));
        array[nb_words - 1] = strndup(&str[i], j - i);
        array[nb_words] = NULL;
        i = j;
    }
    return array;
}
