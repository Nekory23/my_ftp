/*
** EPITECH PROJECT, 2021
** EpitechTools
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

/* INCLUDE */
#include <stdbool.h>

/* STRUCTURES */
#include "server.h"
#include "client.h"

/* MESSAGES */
#include "messages.h"

/* PROTOTYPES */
int start(int ac, char **av);

// start server
bool launch_server(server_t *s, char **av);
void wait_for_connection(server_t *server, client_t *client);
// commands
int gest_command(server_t *server, client_t *client, data_t *data);
int exec_cmd(data_t *data, char *command);
char **split(char *command, char sep);

bool add_client(server_t *server, client_t *client, int fd);
int find_client(data_t **data, int nbr, int fd);

/* STATIC CONST */
// ret vals
static const int SUCCESS = 0;
static const int ERROR = 84;
static const int QUIT = 1;

// errors
static const char ERR_ARG_NBR[] = "This program takes 2 arguments";
static const char ERR_PORT[] = "The port must be a number";
static const char ERR_PATH[] = "The path you gave is not valid";
static const char ERR_HELP[] = " (try again with -help)\n";

#endif /* !MAIN_H_ */
