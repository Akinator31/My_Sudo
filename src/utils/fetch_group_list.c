/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** fetch_group_list
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include "my_lib.h"
#include "my_sudo.h"
#include "my_list.h"
#include "utils.h"

void insert_group(linked_list_t **group_list, char *line, char *username)
{
    char **line_elements = my_str_to_word_array(line);

    for (int i = 0; line_elements[i]; i++) {
        if (!strcmp(username, line_elements[i])) {
            *group_list = push_front_list(*group_list,
            strdup(line_elements[0]));
            return;
        }
    }
    free_2d_array_of_char(line_elements);
}

linked_list_t *fetch_group_list(char *username)
{
    linked_list_t *group_list = NULL;
    FILE *group_file = fopen("/etc/group", "r");
    size_t len = 0;
    char *line = NULL;

    if (!username)
        return NULL;
    while (getline(&line, &len, group_file) != -1)
        insert_group(&group_list, line, username);
    return group_list;
}
