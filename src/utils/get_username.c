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

char *select_username(sudo_arguments_t *args)
{
    if (args->specific_user)
        return args->specific_user;
    else
        return get_uid_string();
}

char *fetch_uid_user(FILE *passwd_file, sudo_arguments_t *args, char *line)
{
    char **string_element = my_str_to_word_array(line);
    char *user = strdup(string_element[0]);

    args->uid = atoi(string_element[2]);
    free_2d_array_of_char(string_element);
    free(line);
    fclose(passwd_file);
    return user;
}

char *get_uid(sudo_arguments_t *args)
{
    FILE *passwd_file = fopen("/etc/passwd", "r");
    char *uid = select_username(args);
    char *line = NULL;
    size_t len = getline(&line, &len, passwd_file);

    while ((int)len != -1) {
        if (strstr(line, uid))
            return fetch_uid_user(passwd_file, args, line);
        len = getline(&line, &len, passwd_file);
    }
    free(line);
    fclose(passwd_file);
    return NULL;
}
