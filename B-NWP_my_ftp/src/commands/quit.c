/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** quit
*/

#include <stdio.h>
#include "my_ftp.h"

int quit(data_t *data)
{
    dprintf(data->fd, QUIT_STR);
    return QUIT;
}