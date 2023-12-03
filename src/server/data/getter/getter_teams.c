/*
** EPITECH PROJECT, 2023
** getter_teams.c
** File description:
** getter_teams
*/

#include "all_data.h"

team_t **get_teams(void)
{
    static team_t *head = NULL;
    return &head;
}
