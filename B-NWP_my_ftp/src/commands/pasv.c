/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** pasv
*/

#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my_ftp.h"

static void display_ip(data_t *data)
{
    char **splitted = split(data->ip, '.');
    int count = 0;;

    for (int i = 0; splitted[i] != NULL; i++)
        if (strcmp(splitted[i], "0") == 0)
            count++;
    if (count == 4)
        dprintf(data->fd, "127,0,0,1,");
    else
        for (int i = 0; splitted[i] != NULL; i++)
            dprintf(data->fd, "%s,", splitted[i]);
    dprintf(data->fd, "%d,%d", data->port / 256, data->port % 256);
}

static bool init_socket(data_t *data)
{
    struct sockaddr_in addr;
    socklen_t size;

    addr.sin_port = htons(0);
    addr.sin_family = PF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    size = sizeof(addr);
    if (bind(data->socket, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return true;
    }
    if (listen(data->socket, 1) == -1) {
        perror("litsen");
        return true;
    }
    if (getsockname(data->socket, (struct sockaddr *)&addr, &size) == -1) {
        perror("getsockname");
        return true;
    }
    data->port = ntohs(addr.sin_port);
    return false;
}

static bool passive_mode(data_t *data)
{
    if (data->socket != -1)
        close(data->socket);
    data->socket = socket(PF_INET, SOCK_STREAM, 0);
    if (data->socket == -1) {
        perror("socket");
        return true;
    }
    if (init_socket(data))
        return true;
    return false;
}

int pasv(data_t *data)
{
    if (!data->login) {
        dprintf(data->fd, PLS_CONNECT);
        return ERROR;
    }
    if (passive_mode(data)) {
        dprintf(data->fd, PASV_ILLEGAL);
        return ERROR;
    }
    data->mode = 0;
    dprintf(data->fd, PASV_ENTER);
    display_ip(data);
    dprintf(data->fd, ").\r\n");
    return SUCCESS;
}