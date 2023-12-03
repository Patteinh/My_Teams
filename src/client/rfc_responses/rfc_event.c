/*
** EPITECH PROJECT, 2023
** rfc_event.c
** File description:
** rfc_event
*/

#include "rfc_client.h"

void call_client_event_team_created(char **infos, const char *response)
{
    printf(response);
    client_event_team_created(infos[0], infos[1], infos[2]);
}

void call_client_event_channel_created(char **infos, const char *response)
{
    printf(response);
    client_event_channel_created(infos[0], infos[1], infos[2]);
}

void call_client_event_thread_created(char **infos, const char *response)
{
    printf(response);
    client_event_thread_created(infos[0], infos[1],
    string_to_time(infos[2]), infos[3], infos[4]);
}

void call_client_event_thread_reply_received
(char **infos, const char *response)
{
    printf(response);
    client_event_thread_reply_received(infos[0], infos[1],
    infos[2], infos[3]);
}

void call_client_event_private_message_received
(char **infos, const char *response)
{
    printf(response);
    client_event_private_message_received(infos[0], infos[1]);
}
