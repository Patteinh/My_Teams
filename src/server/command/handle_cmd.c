/*
** EPITECH PROJECT, 2023
** handle_cmd.c
** File description:
** handle_cmd
*/

#include <string.h>
#include "command.h"

static bool is_authorize(client_t *clt, const command_t *cmd)
{
    return (!cmd->is_log && clt->is_log && strcmp(clt->cmd[0], HELP_CMD))
    || (cmd->is_log && !clt->is_log);
}

static int find_cmd_index(const char *cmd_name)
{
    for (int i = 0; ALLCMD[i].cmd; i++)
        if (!strcmp(cmd_name, ALLCMD[i].cmd))
            return i;
    return FAIL;
}

static int check_cmd_args(int cmd_index, size_t num_args)
{
    for (int i = 0; ALLCMD[cmd_index].nb_args[i] != NOT_FOUND; i++)
        if (ALLCMD[cmd_index].nb_args[i] == num_args)
            return cmd_index;
    return RFC_510.code;
}

static int what_cmd(char **cmd)
{
    int cmd_index = find_cmd_index(cmd[0]);

    if (cmd_index == FAIL)
        return RFC_500.code;
    return check_cmd_args(cmd_index, my_arraylen(cmd) - 1);
}

void handle_cmd(client_t *clt, const char cleaned_buf[MAX_BUF_LEN])
{
    clt->cmd = parse_cmd(cleaned_buf);
    int idx;

    if (!clt->cmd)
        return my_send(clt->socket, RFC_510.response);

    idx = what_cmd(clt->cmd);
    if (idx == RFC_500.code)
        return my_send(clt->socket, RFC_500.response);
    if (idx == RFC_510.code)
        return my_send(clt->socket, RFC_510.response);
    is_authorize(clt, &ALLCMD[idx]) ? my_send(clt->socket, RFC_520.response)
    : ALLCMD[idx].cmd_function(clt);
}
