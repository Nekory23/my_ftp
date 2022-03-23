/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** user
*/

#include <string.h>
#include <stdio.h>
#include "my_ftp.h"

int user(data_t *data)
{
    if (data->login) {
        dprintf(data->fd, USER_ALREADY_LOG);
        return SUCCESS;
    }
    if (data->arguments[1] == NULL) {
        data->username = -1;
        dprintf(data->fd, USER_DENIED);
        return ERROR;
    }
    data->username = 0;
    if (strcmp(data->arguments[1], "Anonymous") == 0)
        data->username = 1;
    dprintf(data->fd, USER_GET_PASS);
    return SUCCESS;
}