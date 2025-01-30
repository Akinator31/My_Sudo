/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** is_group_exist
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool does_group_exist(char *groupname)
{
    FILE *group_file = fopen("/etc/group", "r");
    char *line = NULL;
    size_t len = 0;

    if (!groupname)
        return false;
    while (getline(&line, &len, group_file) != -1) {
        if (strstr(line, groupname)) {
            free(line);
            fclose(group_file);
            return true;
        }
    }
    free(line);
    fclose(group_file);
    return false;
}
