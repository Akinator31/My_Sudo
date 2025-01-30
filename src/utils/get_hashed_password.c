/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** get_hashed_password
*/

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void free_all_here(char *line, FILE *file)
{
    free(line);
    fclose(file);
}

char *get_hashed_password(char *username)
{
    FILE *shadow_file = fopen("/etc/shadow", "r");
    char *line = NULL;
    char *str_token = NULL;
    size_t len = getline(&line, &len, shadow_file);
    char *result = NULL;

    if (!shadow_file | !username)
        return NULL;
    while ((int)len != -1) {
        str_token = strtok(line, ":");
        if (strcmp(str_token, username) == 0) {
            fclose(shadow_file);
            result = strtok(NULL, ":");
            return result;
        }
        len = getline(&line, &len, shadow_file);
    }
    free_all_here(line, shadow_file);
    return NULL;
}
