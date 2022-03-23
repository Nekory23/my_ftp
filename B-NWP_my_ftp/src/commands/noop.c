/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** noop
*/

#include <stdio.h>
#include "my_ftp.h"

int noop(data_t *data)
{
    if (!data->login) {
        dprintf(data->fd, PLS_CONNECT);
        return ERROR;
    }
    dprintf(data->fd, NOOP);
    return SUCCESS;
}