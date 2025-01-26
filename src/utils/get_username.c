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

char *get_uid(void)
{
    FILE *group_file = fopen("/etc/passwd", "r");
    char *uid = get_uid_string();
    const char *separator = ":";
    char *line = NULL;
    size_t len = getline(&line, &len, group_file);
    char *result = NULL;

    while ((int)len != -1) {
        if (strstr(line, uid)) {
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
