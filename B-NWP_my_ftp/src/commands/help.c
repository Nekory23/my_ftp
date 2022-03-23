/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** help
*/

#include <stdio.h>
#include "my_ftp.h"

int help(data_t *data)
{
    if (!data->login) {
        dprintf(data->fd, PLS_CONNECT);
        return ERROR;
    }
    dprintf(data->fd, "%s%s", HELP_FIRST_A, HELP_FIRST_B);
    for (int i = 0; cmds[i].cmd != NULL; i++) {
        dprintf(data->fd, cmds[i].cmd);
        if (cmds[i + 1].cmd != NULL)
            dprintf(data->fd, " ");
    }
    dprintf(data->fd, "\r\n%s", HELP_LAST);
    return SUCCESS;
}