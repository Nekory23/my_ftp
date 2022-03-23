/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <netinet/in.h>

typedef struct server_s {
    int port;
    int sockfd;
    int queue;
    int clients;
    char *path;
    struct sockaddr_in address;
    socklen_t size_addr;
    socklen_t size_socket;
} server_t;

#endif /* !SERVER_H_ */