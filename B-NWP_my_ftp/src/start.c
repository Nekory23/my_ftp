/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** start
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_ftp.h"

static int display_help(char *prog_name)
{
    printf("USAGE: %s port path\n", prog_name);
    printf("\tport\t");
    printf("is the port number on which the server socket listens\n");
    printf("\tpath\t");
    printf("is the path to the home directory for the Anonymous user\n");
    return SUCCESS;
}

static bool display_error(const char *error)
{
    fprintf(stderr, error);
    fprintf(stderr, ERR_HELP);
    return true;
}

static bool error_handling(int ac, char **av)
{
    if (ac != 3)
        return (display_error(ERR_ARG_NBR));
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] < '0' || av[1][i] > '9')
            return (display_error(ERR_PORT));
    }
    if (chdir(av[2]) == -1)
        return (display_error(ERR_PATH));
    return false;
}

int start(int ac, char **av)
{
    server_t server;
    client_t *client = malloc(sizeof(client_t));

    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return (display_help(av[0]));
    if (error_handling(ac, av) || launch_server(&server, av))
        return ERROR;
    wait_for_connection(&server, client);
    free(client);
    return SUCCESS;
}