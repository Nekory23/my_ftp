/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** pwd
*/

#include <stdio.h>
#include "my_ftp.h"

int pwd(data_t *data)
{
    if (!data->login) {
        dprintf(data->fd, PLS_CONNECT);
        return ERROR;
    }
    dprintf(data->fd, "257 \"%s\"\r\n", data->path);
    return SUCCESS;
}