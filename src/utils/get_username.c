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

char *fetch_owner_user(FILE *passwd_file, sudo_arguments_t *args, char *line)
{
    char **string_element = my_str_to_word_array(line);
    char *user = strdup(string_element[0]);
    char *temp = NULL;

    free_2d_array_of_char(string_element);
    free(line);
    fclose(passwd_file);
    return user;
}

char *get_owner_username(sudo_arguments_t *args)
{
    FILE *passwd_file = fopen("/etc/passwd", "r");
    char *uid = get_uid_string(getuid());
    char *line = NULL;
    size_t len = getline(&line, &len, passwd_file);

    while ((int)len != -1) {
        if (strstr(line, uid)) {
            return fetch_owner_user(passwd_file, args, line);
        }
        len = getline(&line, &len, passwd_file);
    }
    free(line);
    fclose(passwd_file);
    return NULL;
}
