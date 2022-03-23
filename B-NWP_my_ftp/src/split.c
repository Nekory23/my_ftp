/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** split
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my_ftp.h"

static int count_parts(char *command, char sep)
{
    int nbr = 0;

    for (int i = 0; command[i] != '\0'; i++)
        if (command[i] == sep)
            nbr++;
    return nbr;
}

static char *convert_to_lowercase(char *to_convert)
{
    for (int i = 0; to_convert[i] != '\0'; i++)
        if (to_convert[i] >= 'a' && to_convert[i] <= 'z')
            to_convert[i] -= 32;
    return to_convert;
}

static char **create_split(int nbr, char *command)
{
    char **split = malloc(sizeof(char *) * (nbr + 2));

    if (split == NULL)
        return NULL;
    for (int i = 0; i != (nbr + 1); i++) {
        split[i] = malloc(sizeof(char) * strlen(command));
        if (split[i] == NULL)
            return NULL;
        split[i] = memset(split[i], '\0', strlen(command));
    }
    return split;
}

static char **simple_split(char *command)
{
    char **split = malloc(sizeof(char *) * 2);

    split[0] = strdup(command);
    split[0] = convert_to_lowercase(split[0]);
    split[1] = NULL;
    return split;
}

char **split(char *command, char sep)
{
    int nbr = count_parts(command, sep);
    char **split;

    if (nbr == 0)
        return (simple_split(command));
    split = create_split(nbr, command);
    if (nbr == -1 || split == NULL)
        return NULL;
    for (int i = 0, j = 0, z = 0; command[i] != '\0'; i++, z++) {
        if (command[i] == sep) {
            split[j][z] = '\0';
            i++;
            j++;
            z = 0;
        }
        split[j][z] = command[i];
    }
    split[0] = convert_to_lowercase(split[0]);
    split[nbr + 1] = NULL;
    return split;
}