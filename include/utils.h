/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** utils
*/

#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H
    #include <stdbool.h>

enum ATTEMPTS_PASSWORD {
    GOOD_PASSWORD,
    TRY_AGAIN,
};

bool check_password(const char *username, const char *password_hash);
char *get_hashed_password(char *username);
bool check_user_permissions(char *username);
char *get_uid(void);
char *get_uid_string(void);
void my_exec(char **args);

#endif
