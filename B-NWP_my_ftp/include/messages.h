/*
** EPITECH PROJECT, 2021
** B-NWP_my_ftp
** File description:
** messages
*/

#ifndef MESSAGES_H_
#define MESSAGES_H_

// DISPLAY
static const char CONNECT[] = "220 (vsFTPd 3.0.0)\r\n";
static const char UNKNOWN_COMMAND[] = "500 Unknown command.\r\n";
static const char PLS_CONNECT[] = "530 Please login with USER and PASS.\r\n";
static const char PLS_MODE[] = "425 Use PORT or PASV first.\r\n";

// COMMANDS
// quit
static const char QUIT_STR[] = "221 Goodbye.\r\n";
// user
static const char USER_DENIED[] = "530 Permission denied.\r\n";
static const char USER_GET_PASS[] = "331 Please specify the password\r\n";
static const char USER_ALREADY_LOG[] = "530 Can't change from guest user.\r\n";
// pass
static const char PASS_SUCCESS[] = "230 Login successful.\r\n";
static const char PASS_FAIL[] = "530 Login incorrect.\r\n";
static const char PASS_USER_FIRST[] = "503 Login with USER first.\r\n";
static const char PASS_ALREADY_LOG[] = "230 Already logged in.\r\n";
// noop
static const char NOOP[] = "200 NOOP ok.\r\n";
// help
static const char HELP_FIRST_A[] = "214-The following ";
static const char HELP_FIRST_B[] = "commands are recognized.\r\n";
static const char HELP_LAST[] = "214 Help OK.\r\n";
// pasv
static const char PASV_ENTER[] = "227 Entering Passive Mode (";
static const char PASV_ILLEGAL[] = "500 Illegal PASV.\r\n";
// cdup
static const char CDUP_SUCCESS[] = "250 Directory successfully changed.\r\n";
static const char CDUP_FAIL[] = "550 Failed to change directory.\r\n";
// cwd
static const char CWD_SUCCESS[] = "250 Directory successfully changed.\r\n";
static const char CWD_FAIL[] = "550 Failed to change directory.\r\n";

#endif /* !MESSAGES_H_ */