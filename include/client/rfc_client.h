/*
** EPITECH PROJECT, 2023
** rfc.h
** File description:
** rfc
*/

#pragma once

#include <stdio.h>
#include "client.h"

#define SEND(sock, message) (void)dprintf((sock), (message))
#define TIMESTAMP_FORMAT "%d-%d-%d %d:%d:%d"

typedef struct rfc_s {
    const int code;
    void (*const code_function)(char **, const char *);
    const char *response;
} rfc_t;

void call_client_help(char **infos, const char *response);
void call_client_event_logged_in(char **infos, const char *response);
void call_client_event_logged_out(char **infos, const char *response);
void call_client_print_subscribed(char **infos, const char *response);
void call_client_print_unsubscribed(char **infos, const char *response);
void call_client_print_team_created(char **infos, const char *response);
void call_client_event_team_created(char **infos, const char *response);
void call_client_print_channel_created(char **infos, const char *response);
void call_client_event_channel_created(char **infos, const char *response);
void call_client_print_thread_created(char **infos, const char *response);
void call_client_event_thread_created(char **infos, const char *response);
void call_client_print_reply_created(char **infos, const char *response);
void call_client_event_thread_reply_received
(char **infos, const char *response);
void call_client_event_private_message_received
(char **infos, const char *response);
void call_client_print_user(char **infos, const char *response);
void call_client_print_team(char **infos, const char *response);
void call_client_print_channel(char **infos, const char *response);
void call_client_print_thread(char **infos, const char *response);
void call_client_usage_team(char **infos, const char *response);
void call_client_usage_channel(char **infos, const char *response);
void call_client_usage_thread(char **infos, const char *response);
void call_client_print_users(char **infos, const char *response);
void call_client_print_teams(char **infos, const char *response);
void call_client_team_print_channels(char **infos, const char *response);
void call_client_channel_print_threads(char **infos, const char *response);
void call_client_thread_print_replies(char **infos, const char *response);
void call_client_private_message_print_messages
(char **infos, const char *response);
void call_client_error_unknown_user(char **infos, const char *response);
void call_client_error_unknown_team(char **infos, const char *response);
void call_client_error_unknown_channel(char **infos, const char *response);
void call_client_error_unknown_thread(char **infos, const char *response);
void call_client_no_teams_found(char **infos, const char *response);
void call_client_no_teams_subscriptions_found
(char **infos, const char *response);
void call_client_no_channels_found(char **infos, const char *response);
void call_client_no_threads_found(char **infos, const char *response);
void call_client_no_replies_found(char **infos, const char *response);
void call_client_no_messages_found(char **infos, const char *response);
void call_client_no_clients_subscriptions_to_team_found
(char **infos, const char *response);
void call_client_error_cmd_not_found(char **infos, const char *response);
void call_client_error_invalid_args_in_cmd(char **infos, const char *response);
void call_client_error_unauthorized(char **infos, const char *response);
void call_client_error_already_exist(char **infos, const char *response);

static const char R100[] = "[100] Please check My-Teams_RFC_protocol.pdf.\r\n";
static const char R210[] = "[210] User logged in.\r\n";
static const char R220[] = "[220] User logged out.\r\n";
static const char R230[] = "[230] Successfully subscribed.\r\n";
static const char R240[] = "[240] Successfully unsubscribed.\r\n";
static const char R250[] = "[250] New team created.\r\n";
static const char R255[] = "[255] Event new team was created.\r\n";
static const char R260[] = "[260] New channel created.\r\n";
static const char R265[] = "[265] Event new channel was created.\r\n";
static const char R270[] = "[270] New thread created.\r\n";
static const char R275[] = "[275] Event new thread was created.\r\n";
static const char R280[] = "[280] New reply for thread created.\r\n";
static const char R285[] = "[285] Event new reply for thread was created.\r\n";
static const char R290[] = "[290] Event new message received.\r\n";
static const char R300[] = "[300] User informations.\r\n";
static const char R310[] = "[310] Team informations.\r\n";
static const char R320[] = "[320] Channel informations.\r\n";
static const char R330[] = "[330] Thread informations.\r\n";
static const char R333[] = "[333] Using selected Team.\r\n";
static const char R336[] = "[336] Using selected Channel.\r\n";
static const char R339[] = "[339] Using selected Thread.\r\n";
static const char R340[] = "[340] All Users informations.\r\n";
static const char R350[] = "[350] All Teams informations.\r\n";
static const char R360[] = "[360] All Channels informations.\r\n";
static const char R370[] = "[370] All Threads informations.\r\n";
static const char R380[] = "[380] All Threads replies informations.\r\n";
static const char R390[] = "[390] All Messages informations.\r\n";
static const char R400[] = "[400] Unknow User.\r\n";
static const char R410[] = "[410] Unknow Team.\r\n";
static const char R420[] = "[420] Unknow Channel.\r\n";
static const char R430[] = "[430] Unknow Thread.\r\n";
static const char R450[] = "[450] No Teams found.\r\n";
static const char R455[] = "[455] No Teams subscriptions found.\r\n";
static const char R460[] = "[460] No Channels found.\r\n";
static const char R470[] = "[470] No Threads found.\r\n";
static const char R480[] = "[480] No Threads replies found.\r\n";
static const char R490[] = "[490] No Messages found.\r\n";
static const char R495[] = "[495] No Clients subscriptions to team found.\r\n";
static const char R500[] = "[500] Command not found.\r\n";
static const char R510[] = "[510] Command written with wrong args.\r\n";
static const char R520[] = "[520] Command not authorized.\r\n";
static const char R530[] = "[530] Request already exist.\r\n";

static const rfc_t RFC[] =
{
    {100, call_client_help, R100},
    {210, call_client_event_logged_in, R210},
    {220, call_client_event_logged_out, R220},
    {230, call_client_print_subscribed, R230},
    {240, call_client_print_unsubscribed, R240},
    {250, call_client_print_team_created, R250},
    {255, call_client_event_team_created, R255},
    {260, call_client_print_channel_created, R260},
    {265, call_client_event_channel_created, R265},
    {270, call_client_print_thread_created, R270},
    {275, call_client_event_thread_created, R275},
    {280, call_client_print_reply_created, R280},
    {285, call_client_event_thread_reply_received, R285},
    {290, call_client_event_private_message_received, R290},
    {300, call_client_print_user, R300},
    {310, call_client_print_team, R310},
    {320, call_client_print_channel, R320},
    {330, call_client_print_thread, R330},
    {333, call_client_usage_team, R333},
    {336, call_client_usage_channel, R336},
    {339, call_client_usage_thread, R339},
    {340, call_client_print_users, R340},
    {350, call_client_print_teams, R350},
    {360, call_client_team_print_channels, R360},
    {370, call_client_channel_print_threads, R370},
    {380, call_client_thread_print_replies, R380},
    {390, call_client_private_message_print_messages, R390},
    {400, call_client_error_unknown_user, R400},
    {410, call_client_error_unknown_team, R410},
    {420, call_client_error_unknown_channel, R420},
    {430, call_client_error_unknown_thread, R430},
    {450, call_client_no_teams_found, R450},
    {455, call_client_no_teams_subscriptions_found, R455},
    {460, call_client_no_channels_found, R460},
    {470, call_client_no_threads_found, R470},
    {480, call_client_no_replies_found, R480},
    {490, call_client_no_messages_found, R490},
    {495, call_client_no_clients_subscriptions_to_team_found, R495},
    {500, call_client_error_cmd_not_found, R500},
    {510, call_client_error_invalid_args_in_cmd, R510},
    {520, call_client_error_unauthorized, R520},
    {530, call_client_error_already_exist, R530},
};

int what_code(receive_infos_t *infos);
time_t string_to_time(const char *timestamp_str);
