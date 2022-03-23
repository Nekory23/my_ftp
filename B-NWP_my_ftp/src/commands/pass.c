/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** pass
*/

#include <stdio.h>
#include "my_ftp.h"

int pass(data_t *data)
{
    if (data->login) {
        dprintf(data->fd, PASS_ALREADY_LOG);
        return ERROR;
    }
    if (data->username == -1 && data->login == false) {
        dprintf(data->fd, PASS_USER_FIRST);
        return ERROR;
    }
    if (data->arguments[1] == NULL && data->username == 1) {
        data->login = true;
        dprintf(data->fd, PASS_SUCCESS);
        return SUCCESS;
    }
    dprintf(data->fd, PASS_FAIL);
    data->username = -1;
    return ERROR;
}