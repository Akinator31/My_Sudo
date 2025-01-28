/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** errors
*/

#ifndef INCLUDED_ERRORS_H
    #define INCLUDED_ERRORS_H

int incorrect_username(sudo_arguments_t *args);
int incorrect_password(sudo_arguments_t *args);
int user_not_in_sudoers(char *username, char *groupname);
int incorrect_groupname(sudo_arguments_t *args);
int errors_manager(sudo_arguments_t *args, char *group, int attempts);

#endif
