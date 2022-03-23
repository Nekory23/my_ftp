/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** manage_client
*/

#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_ftp.h"

int find_client(data_t **data, int nbr, int fd)
{
    int i = 0;

    for (; i != nbr; i++)
        if (data[i]->fd == fd)
            break;
    return i;
}

static bool check_exist(data_t **data, int fd, int nbr)
{
    if (data == NULL)
        return false;
    for (int i = 0; i != nbr; i++)
        if (data[i]->fd == fd)
            return true;
    return false;
}

static void fill_client(client_t *client, server_t *server, int fd)
{
    client->data[server->clients-1]->arguments = NULL;
    client->data[server->clients-1]->fd = fd;
    client->data[server->clients-1]->login = false;
    client->data[server->clients-1]->username = -1;
    client->data[server->clients-1]->mode = -1;
    client->data[server->clients-1]->port = -1;
    client->data[server->clients-1]->ip = inet_ntoa(client->address.sin_addr);
    client->data[server->clients-1]->path = server->path;
}

bool add_client(server_t *server, client_t *client, int fd)
{
    if (check_exist(client->data, fd, server->clients))
        return false;
    server->clients += 1;
    client->data = reallocarray(client->data,
    sizeof(data_t *), (size_t) server->clients);
    if (client->data == NULL) {
        perror("reallocarray");
        return true;
    }
    client->data[server->clients - 1] = malloc(sizeof(data_t));
    if (client->data[server->clients - 1] == NULL) {
        perror("malloc");
        return true;
    }
    fill_client(client, server, fd);
    return false;
}