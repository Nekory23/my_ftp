/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** gest_command
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_ftp.h"

static int manage_quit(server_t *server, client_t *client, data_t *data)
{
    server->clients -= 1;
    FD_CLR(data->fd, &client->active_fd);
    close(data->fd);
    free(data);
    return SUCCESS;
}

static char *clean_str(char *str)
{
    int space = 0;
    char *clean = malloc(sizeof(char) * (strlen(str) + 2));

    memset(clean, '\0', (strlen(str) + 2));
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\t')
            str[i] = ' ';
    for (space = 0; str[space] == ' '; space++);
    for (int i = 0; str[space] != '\0'; space++)
        if (!(str[space] == ' ' && str[space + 1] == ' ')) {
            clean[i] = str[space];
            i++;
        }
    if (clean[strlen(clean) - 3] == ' ') {
        clean[strlen(clean) - 3] = clean[strlen(clean) - 2];
        clean[strlen(clean) - 2] = clean[strlen(clean) - 1];
        clean[strlen(clean) - 1] = '\0';
    }
    free(str);
    return (clean);
}

static char *get_command(data_t *data)
{
    int ret = 0;
    size_t size = 500;
    char *buff = malloc(sizeof(char) * size);
    char *command;

    if (buff == NULL) {
        perror("malloc");
        return NULL;
    }
    buff = memset(buff, '\0', size);
    ret = read(data->fd, buff, size);
    if (ret == 0|| ret == -1) {
        perror("read");
        free(buff);
        return NULL;
    }
    command = clean_str(buff);
    return command;
}

int gest_command(server_t *server, client_t *client, data_t *data)
{
    int ret = 0;
    char *command = get_command(data);

    if (command == NULL)
        return ERROR;
    ret = exec_cmd(data, command);
    if (ret == QUIT) {
        free(command);
        return (manage_quit(server, client, data));
    }
    free(command);
    return SUCCESS;
}