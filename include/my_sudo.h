/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** my_sudo
*/

#ifndef INCLUDED_MY_SUDO_H
    #define INCLUDED_MY_SUDO_H
    #include <stdbool.h>
    #include "my_list.h"

typedef struct sudo_arguments_s sudo_arguments_t;

enum args_name {
    HELP,
    USER_SPECIFIC,
    GROUP_SPECIFIC,
    PRESERVE_ENV,
    SHELL
};

struct sudo_arguments_s {
    linked_list_t *group_list;
    unsigned int owner_uid;
    int specific_user_uid;
    char *owner_username;
    char *specific_user;
    char *specific_group;
    bool preserve_env;
    bool execute_shell;
    int start_index;
    int help;
    int incorrect_groupname;
    int incorrect_username;
};

bool help_flag(sudo_arguments_t *args, char character);
bool user_flag(sudo_arguments_t *args, char character, char *argument);
bool group_flag(sudo_arguments_t *args, char character, char *argument);
void shell_flag(sudo_arguments_t *args, char character, char next_character);
void preserve_environment_flag(sudo_arguments_t *args, char character,
    char next_character);

#endif
