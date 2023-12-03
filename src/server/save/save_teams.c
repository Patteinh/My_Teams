/*
** EPITECH PROJECT, 2023
** save_teams.c
** File description:
** save_teams
*/

#include "save.h"

void save_teams(team_t *team, FILE *file)
{
    if (team) {
        fprintf(file, TEAMS_P);
        while (team) {
            fprintf(file, TEAM_PARSER,
                team->uuid, team->name, team->description);
            team = team->next;
        }
    } else {
        fprintf(file, NO_TEAMS_DATA);
    }
    fprintf(file, END_OF_SECTION);
}
