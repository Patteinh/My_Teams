/*
** EPITECH PROJECT, 2023
** load_teams.c
** File description:
** load_teams
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "load.h"

static team_t *parse_team_lines(FILE *file)
{
    team_t *team = malloc(sizeof(team_t));
    char line[MAX_BUF_LEN];

    memset(team, 0, sizeof(team_t));
    fgets(line, sizeof(line), file);
    sscanf(line, UUID_PARSER, team->uuid);
    fgets(line, sizeof(line), file);
    sscanf(line, NAME_PARSER, team->name);
    fgets(line, sizeof(line), file);
    sscanf(line, DESCRIPTION_PARSER, team->description);
    team->next = NULL;
    return team;
}

team_t *load_teams(FILE *file)
{
    team_t *teams = NULL;
    team_t *prev = NULL;
    char line[MAX_BUF_LEN];

    while (fgets(line, sizeof(line), file) && strcmp(line, END_OF_SECTION)) {
        team_t *team = parse_team_lines(file);
        prev ? prev->next = team :
        !prev ? teams = team : 0;
        prev = team;
    }
    return teams;
}
