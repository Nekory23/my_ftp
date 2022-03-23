/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <stddef.h>
#include <netinet/in.h>

/* DATA STRUCTURE */
typedef struct data_s {
    int fd;
    int socket;
    int username;
    int port;
    int mode;
    bool login;
    char **arguments;
    char *ip;
    char *path;
} data_t;

/* CLIENT STRUCTURE */
typedef struct client_s {
    int sockfd;
    struct sockaddr_in address;
    fd_set active_fd;
    fd_set read_fd;
    data_t **data;
} client_t;

/* COMMANDS */
int user(data_t *data);
int pass(data_t *data);
int cwd(data_t *data);
int cdup(data_t *data);
int quit(data_t *data);
int dele(data_t *data);
int pwd(data_t *data);
int pasv(data_t *data);
int port(data_t *data);
int help(data_t *data);
int noop(data_t *data);
int retr(data_t *data);
int stor(data_t *data);
int list(data_t *data);

typedef struct cmd_s
{
    const char *cmd;
    int (*func_ptr)(data_t *data);
} cmd_t;

static const cmd_t cmds[] =
{
    {"USER\0", &user},
    {"PASS\0", &pass},
    {"CWD\0", &cwd},
    {"CDUP\0", &cdup},
    {"QUIT\0", &quit},
    {"DELE\0", &dele},
    {"PWD\0", &pwd},
    {"PASV\0", &pasv},
    {"PORT\0", &port},
    {"HELP\0", &help},
    {"NOOP\0", &noop},
    {"RETR\0", &retr},
    {"STOR\0", &stor},
    {"LIST\0", &list},
    {NULL, NULL}
};

#endif /* !CLIENT_H_ */