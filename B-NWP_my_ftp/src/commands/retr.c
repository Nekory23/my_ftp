/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** retr
*/

#include <stdio.h>
#include "my_ftp.h"

int retr(data_t *data)
{
    if (!data->login) {
        dprintf(data->fd, PLS_CONNECT);
        return ERROR;
    }
    if (data->mode == -1) {
        dprintf(data->fd, PLS_MODE);
        return ERROR;
    }
    return SUCCESS;
}