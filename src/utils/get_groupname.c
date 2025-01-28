/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** get_username
*/

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "my_sudo.h"
#include "my_lib.h"

char *select_groupname(sudo_arguments_t *args)
{
    if (args->specific_group)
        return args->specific_group;
    else
        return get_uid_string();
}

char *fetch_gid_user(FILE *group_file, sudo_arguments_t *args, char *line)
{
    char **string_element = my_str_to_word_array(line);
    char *group = strdup(string_element[0]);

    args->uid = atoi(string_element[2]);
    free_2d_array_of_char(string_element);
    free(line);
    fclose(group_file);
    return group;
}

char *get_gid(sudo_arguments_t *args)
{
    FILE *group_file = fopen("/etc/group", "r");
    char *gid = select_groupname(args);
    char *line = NULL;
    size_t len = getline(&line, &len, group_file);

    while ((int)len != -1) {
        if (strstr(line, gid)) {
            free(gid);
            return fetch_gid_user(group_file, args, line);
        }
        len = getline(&line, &len, group_file);
    }
    free(line);
    fclose(group_file);
    return NULL;
}
