/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** init_server
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_ftp.h"

static bool gest_error(server_t *server, const char *error)
{
    if (error != NULL)
        perror(error);
    close(server->sockfd);
    return true;
}

static void fill_args(server_t *server, char **args)
{
    server->port = atoi(args[1]);
    server->path = args[2];
    server->clients = 0;
}

bool launch_server(server_t *s, char **av)
{
    fill_args(s, av);
    s->sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (s->sockfd == -1)
        return (gest_error(s, "socket"));
    s->address.sin_family = PF_INET;
    s->address.sin_port = htons(s->port);
    s->address.sin_addr.s_addr = INADDR_ANY;
    s->size_addr = sizeof(s->address);
    s->size_socket = sizeof(s->sockfd);
    if (bind(s->sockfd, (struct sockaddr *)&s->address, s->size_addr) == -1) {
        shutdown(s->sockfd, SHUT_RDWR);
        return (gest_error(s, "bind"));
    }
    s->queue = listen(s->sockfd, 1000);
    if (s->queue == -1)
        return (gest_error(s, NULL));
    return false;
}