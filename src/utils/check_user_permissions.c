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
#include "my_list.h"
#include "utils.h"

char *get_uid_string(unsigned int uid)
{
    int uid_length = snprintf(NULL, 0, "%d", uid);
    char *result = calloc(uid_length + 3, sizeof(char));
    char *uid_to_str = calloc(uid_length + 1, sizeof(char));

    result = strcat(result, ":");
    sprintf(uid_to_str, "%d", uid);
    result = strcat(result, uid_to_str);
    result = strcat(result, ":");
    free(uid_to_str);
    return result;
}

char *get_gid_string(void)
{
    unsigned int gid = getgid();
    int gid_length = snprintf(NULL, 0, "%d", gid);
    char *result = calloc(gid_length + 3, sizeof(char));
    char *gid_to_str = calloc(gid_length + 1, sizeof(char));

    result = strcat(result, ":");
    sprintf(gid_to_str, "%d", gid);
    result = strcat(result, gid_to_str);
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

char *is_usergroup_in_sudoers(char *groupname)
{
    FILE *group_file = fopen("/etc/sudoers", "r");
    char *line = NULL;
    size_t len = getline(&line, &len, group_file);
    char *result = NULL;

    while ((int)len != -1) {
        if (strstr(line, groupname)) {
            result = strdup(strtok(line, ":"));
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

bool check_user_permissions(char *username, linked_list_t *group_list)
{
    if (is_user_in_sudoers(username)) {
        return true;
    }
    if (is_grouplist_in_sudoers(group_list))
        return true;
    return false;
}
