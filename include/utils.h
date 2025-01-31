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
    #include "my_list.h"

enum ATTEMPTS_PASSWORD {
    GOOD_PASSWORD,
    TRY_AGAIN,
    CONTINUE,
    GOOD_NB_ATTEMPTS,
    INCORRECT_GROUPNAME,
    INCORRECT_USERNAME,
};

bool check_password(sudo_arguments_t *args, const char *username,
    const char *password_hash, int *attempt);
char *get_hashed_password(char *username);
bool check_user_permissions(char *username, linked_list_t *group_list);
char *get_owner_username(void);
char *get_gid(sudo_arguments_t *args);
char *get_uid_string(unsigned int uid);
char *get_gid_string(void);
int my_exec(sudo_arguments_t *sudo_params, char **args);
sudo_arguments_t *parse_arguments(int ac, char **av);
void destroy_sudo_args(sudo_arguments_t *args);
int display_help_message(sudo_arguments_t *args, int error_code);
sudo_arguments_t *create_sudo_args_struct(void);
void print_sudo_args(sudo_arguments_t *args);
void free_2d_array_of_char(char **arr);
linked_list_t *fetch_group_list(char *username);
bool is_groupname_in_grouplist(linked_list_t *group_list, char *groupname);
bool is_grouplist_in_sudoers(linked_list_t *group_list);
bool does_group_exist(char *groupname);
int get_uid_from_user(char *username);
bool does_user_exist(char *username);

#endif
