/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** exec_cmd
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my_ftp.h"

static char *check_for_crlf(char *command)
{
    int len = strlen(command);

    if (command[len - 2] != '\r' || command[len - 1] != '\n')
        return NULL;
    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == '\n') {
            command[i] = '\0';
            i = 0;
        }
        if (command[i] == '\r')
            command[i] = '\0';
    }
    return command;
}

static void free_split(char **splitted)
{
    for (int i = 0; splitted[i] != NULL; i++)
        free(splitted[i]);
    free(splitted);
}

static char **get_splitted(char *command)
{
    char **splitted;

    command = check_for_crlf(command);
    if (command == NULL)
        return NULL;
    splitted = split(command, ' ');
    if (splitted == NULL)
        return NULL;
    for (int i = 0; splitted[0][i] != '\0'; i++)
        if (splitted[0][i] == '\n' || splitted[0][i] == '\r')
            splitted[0][i] = '\0';
    return splitted;
}

int exec_cmd(data_t *data, char *command)
{
    int ret = -1;

    data->arguments = get_splitted(command);
    if (data->arguments == NULL)
        return ERROR;
    for (int i = 0; cmds[i].cmd != NULL; i++) {
        if (strcmp(cmds[i].cmd, data->arguments[0]) == 0)
            ret = cmds[i].func_ptr(data);
        if (ret == QUIT) {
            free_split(data->arguments);
            return QUIT;
        }
    }
    if (ret == -1)
        dprintf(data->fd, UNKNOWN_COMMAND);
    free_split(data->arguments);
    return SUCCESS;
}