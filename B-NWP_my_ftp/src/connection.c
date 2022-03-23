/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** connection
*/

#include <sys/select.h>
#include <stdio.h>
#include <unistd.h>
#include "my_ftp.h"

static int loop_fds(server_t *server, client_t *client, int i)
{
    int current = -1;

    if (FD_ISSET(i, &client->read_fd)) {
        if (i == server->sockfd) {
            client->sockfd = accept(server->sockfd,
            (struct sockaddr *)&client->address, &server->size_socket);
            if (client->sockfd == -1) {
                perror("accept");
                return ERROR;
            }
            dprintf(client->sockfd, CONNECT);
            FD_SET(client->sockfd, &client->active_fd);
        }
        else if (client->sockfd != -1) {
            if (add_client(server, client, i))
                return ERROR;
            current = find_client(client->data, server->clients, i);
            return (gest_command(server, client, client->data[current]));
        }
    }
    return SUCCESS;
}

void wait_for_connection(server_t *server, client_t *client)
{
    client->data = NULL;
    FD_ZERO(&client->active_fd);
    FD_SET(server->sockfd, &client->active_fd);
    while (777) {
        client->read_fd = client->active_fd;
        if (select(FD_SETSIZE, &client->read_fd, NULL, NULL, NULL) < 0) {
            perror("select");
            break;
        }
        for (int i = 0; i != FD_SETSIZE; i++)
            if (loop_fds(server, client, i) == ERROR) {
                close(server->sockfd);
                return;
            }
    }
    close(server->sockfd);
}