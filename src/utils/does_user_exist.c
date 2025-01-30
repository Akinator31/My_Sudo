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

bool does_user_exist(char *username)
{
    FILE *passwd_file = fopen("/etc/passwd", "r");
    char *line = NULL;
    size_t len = 0;

    if (!username)
        return false;
    while (getline(&line, &len, passwd_file) != -1) {
        if (strstr(line, username)) {
            free(line);
            fclose(passwd_file);
            return true;
        }
    }
    free(line);
    fclose(passwd_file);
    return false;
}
