/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** port
*/

#include <stdio.h>
#include "my_ftp.h"

int port(data_t *data)
{
    if (!data->login) {
        dprintf(data->fd, PLS_CONNECT);
        return ERROR;
    }
    return SUCCESS;
}