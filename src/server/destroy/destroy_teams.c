/*
** EPITECH PROJECT, 2023
** destroy_teams.c
** File description:
** destroy_teams
*/

#include <stdlib.h>
#include "destroy.h"

void free_teams(team_t *team)
{
    for (team_t *tmp; team; team = tmp) {
        tmp = team->next;
        free(team);
    }
}
