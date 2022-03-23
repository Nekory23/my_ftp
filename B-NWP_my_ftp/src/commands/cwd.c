/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** cwd
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my_ftp.h"

static int gest_error(data_t *data, const char *error)
{
    dprintf(data->fd, error);
    return ERROR;
}

int cwd(data_t *data)
{
    char *new_path;
    int size;

    if (!data->login)
        return (gest_error(data, PLS_CONNECT));
    if (data->arguments[1] == NULL)
        return (gest_error(data, CWD_FAIL));
    if (chdir(data->arguments[1]) == -1)
        return (gest_error(data, CWD_FAIL));
    size = strlen(data->path) + strlen(data->arguments[1]) + 2;
    new_path = malloc(sizeof(char) * size);
    new_path = strcat(data->path, "/");
    new_path = strcat(new_path, data->arguments[1]);
    data->path = new_path;
    dprintf(data->fd, CWD_SUCCESS);
    return SUCCESS;
}