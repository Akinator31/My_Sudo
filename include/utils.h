/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** utils
*/

#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H
    #include <stdbool.h>
    #include "my_sudo.h"

enum ATTEMPTS_PASSWORD {
    GOOD_PASSWORD,
    TRY_AGAIN,
};

bool check_password(const char *username, const char *password_hash);
char *get_hashed_password(char *username);
bool check_user_permissions(char *username);
char *get_uid(sudo_arguments_t *args);
char *get_uid_string(void);
void my_exec(sudo_arguments_t *sudo_params, char **args);
sudo_arguments_t *parse_arguments(int ac, char **av);
void destroy_sudo_args(sudo_arguments_t *args);
int display_help_message(void);
sudo_arguments_t *create_sudo_args_struct(void);
void print_sudo_args(sudo_arguments_t *args);
void free_2d_array_of_char(char **arr);

#endif
