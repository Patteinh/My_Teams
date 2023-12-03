/*
** EPITECH PROJECT, 2023
** all_data.h
** File description:
** all_data
*/

#pragma once

#include <uuid/uuid.h>
#include <stdbool.h>

#define MAX_BODY_LEN 512
#define MAX_NAME_LEN 32
#define MAX_DESCRIPTION_LEN 255
#define MAX_BUF_LEN 1024
#define GIVE_UUID(uuid_var) ({ \
    uuid_t _binuuid; \
    char _uuid[UUID_STR_LEN] = {0}; \
    uuid_generate_random(_binuuid); \
    uuid_unparse_upper(_binuuid, _uuid); \
    uuid_var = strdup(_uuid); \
})

static const char CLIENTS_P[] = "- Clients\n";
static const char DISCUSSIONS_P[] = "- Discussions\n";
static const char SUBSCRIPTIONS_P[] = "- Subscriptions\n";
static const char REPLIES_P[] = "- Replies\n";
static const char THREADS_P[] = "- Threads\n";
static const char CHANNELS_P[] = "- Channels\n";
static const char TEAMS_P[] = "- Teams\n";
static const char END_OF_DATA[] = "- End of data";
static const char NO_DATA_PATTERN[] = "- No data\n";
static const char END_OF_SECTION[] = "\n";

typedef enum {
    USE_NONE,
    USE_TEAM,
    USE_CHANNEL,
    USE_THREAD
} use_type_e;

typedef struct team_s {
    char uuid[UUID_STR_LEN];
    char name[MAX_NAME_LEN];
    char description[MAX_BODY_LEN];
    struct team_s *next;
} team_t;

typedef struct channel_s {
    char uuid[UUID_STR_LEN];
    char team_uuid[UUID_STR_LEN];
    char name[MAX_NAME_LEN];
    char description[MAX_BODY_LEN];
    struct channel_s *next;
} channel_t;

typedef struct thread_s {
    char creator_uuid[UUID_STR_LEN];
    char uuid[UUID_STR_LEN];
    char channel_uuid[UUID_STR_LEN];
    char title[MAX_NAME_LEN];
    char body[MAX_BODY_LEN];
    time_t timestamp;
    struct thread_s *next;
} thread_t;

typedef struct reply_s {
    char creator_uuid[UUID_STR_LEN];
    char uuid[UUID_STR_LEN];
    char thread_uuid[UUID_STR_LEN];
    char body[MAX_BODY_LEN];
    time_t timestamp;
    struct reply_s *next;
} reply_t;

typedef struct discussion_s {
    char sender_uuid[UUID_STR_LEN];
    char receiver_uuid[UUID_STR_LEN];
    char body[MAX_BODY_LEN];
    time_t timestamp;
    struct discussion_s *next;
} discussion_t;

typedef struct subscription_s {
    char user_uuid[UUID_STR_LEN];
    char team_uuid[UUID_STR_LEN];
    struct subscription_s *next;
} subscription_t;

typedef struct client_s {
    char uuid[UUID_STR_LEN];
    char name[MAX_NAME_LEN];
    char use_team_uuid[UUID_STR_LEN];
    char use_channel_uuid[UUID_STR_LEN];
    char use_thread_uuid[UUID_STR_LEN];
    bool server_close;
    bool is_log;
    bool online;
    int socket;
    char **cmd;
    use_type_e current_use;
    struct client_s *next;
} client_t;

client_t **get_clients(void);
discussion_t **get_discussions(void);
subscription_t **get_subscriptions(void);
team_t **get_teams(void);
channel_t **get_channels(void);
thread_t **get_threads(void);
reply_t **get_replies(void);
