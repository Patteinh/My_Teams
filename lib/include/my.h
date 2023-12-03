/*
** EPITECH PROJECT, 2023
** lib.h
** File description:
** lib.h
*/

#pragma once

#include <stddef.h>

size_t my_arraylen(char **array);
char *my_clean_str(const char *str, const char *d);
char **my_str_to_array(const char *str, const char *d);
void my_free_array(char **array);

static const int SUCCESS = 0;
static const int FAILURE = 1;
static const int ERROR = 84;
