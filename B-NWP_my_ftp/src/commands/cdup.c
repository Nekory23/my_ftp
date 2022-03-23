/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** cdup
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my_ftp.h"

int cdup(data_t *data)
{
    char *new_path;
    int size;

    if (!data->login) {
        dprintf(data->fd, PLS_CONNECT);
        return ERROR;
    }
    size = strlen(data->path) + strlen("/..") + 1;
    new_path = malloc(sizeof(char) * size);
    if (chdir("./..") != -1) {
        new_path = strcat(data->path, "/..");
        data->path = new_path;
        dprintf(data->fd, CDUP_SUCCESS);
        return ERROR;
    }
    dprintf(data->fd, CDUP_FAIL);
    return SUCCESS;
}