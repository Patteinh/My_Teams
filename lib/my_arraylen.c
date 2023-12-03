/*
** EPITECH PROJECT, 2023
** my_strlen_array
** File description:
** count line in array
*/

#include <stddef.h>

size_t my_arraylen(char **array)
{
    size_t len = 0;

    while (array[++len]);
    return len;
}
