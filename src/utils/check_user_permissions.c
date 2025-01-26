/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** is_user_in_sudoers
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *get_uid_string(void)
{
    unsigned int uid = getuid();
    int uid_length = snprintf(NULL, 0, "%d", uid);
    char *result = calloc(uid_length + 3, sizeof(char));
    char *uid_to_str = calloc(uid_length + 1, sizeof(char));

    result = strcat(result, ":");
    sprintf(uid_to_str, "%d", uid);
    result = strcat(result, uid_to_str);
    result = strcat(result, ":");
    return result;
}

bool is_user_in_sudoers(char *username)
{
    FILE *passwd_file = fopen("/etc/sudoers", "r");
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, passwd_file) != -1) {
        if (strstr(line, username)) {
            fclose(passwd_file);
            free(line);
            return true;
        }
    }
    fclose(passwd_file);
    free(line);
    return false;
}

char *is_usergroup_in_sudoers(char *username)
{
    FILE *group_file = fopen("/etc/group", "r");
    const char *separator = ":";
    char *line = NULL;
    size_t len = getline(&line, &len, group_file);
    char *result = NULL;

    while ((int)len != -1) {
        if (strstr(line, username)) {
            result = strdup(strtok(line, separator));
            free(line);
            fclose(group_file);
            return result;
        }
        len = getline(&line, &len, group_file);
    }
    free(line);
    fclose(group_file);
    return NULL;
}

bool check_user_permissions(char *username)
{
    if (is_user_in_sudoers(username))
        return true;
    if (is_usergroup_in_sudoers(username))
        return true;
    return false;
}
