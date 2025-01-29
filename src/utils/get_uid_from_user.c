/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** get_uid_from_user
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_lib.h"
#include "utils.h"

unsigned int fetch_uid_from_user(char *line)
{
    char **line_elements = my_str_to_word_array(line);
    unsigned int result = atoi(line_elements[2]);

    free_2d_array_of_char(line_elements);
    return result;
}

int get_uid_from_user(char *username)
{
    FILE *passwd_file = fopen("/etc/passwd", "r");
    char *line = NULL;
    size_t len = 0;
    unsigned int result = 0;

    if (!username)
        return 0;
    while (getline(&line, &len, passwd_file) != -1) {
        if (strstr(line, username)) {
            result = fetch_uid_from_user(line);
            free(line);
            fclose(passwd_file);
            return result;
        }
    }
    free(line);
    fclose(passwd_file);
    return -1;
}
