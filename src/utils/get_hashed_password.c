/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** get_hashed_password
*/

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>

char *get_hashed_password(char *username)
{
    FILE *shadow_file = fopen("/etc/shadow", "r");
    char *line = NULL;
    const char *separator = ":";
    char *str_token = NULL;
    size_t len = 0;

    if (!shadow_file)
        return NULL;
    while (getline(&line, &len, shadow_file) != -1) {
        str_token = strtok(line, separator);
        if (strcmp(str_token, username) == 0) {
            fclose(shadow_file);
            return strtok(NULL, separator);
        }
    }
    fclose(shadow_file);
    return NULL;
}
