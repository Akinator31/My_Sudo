/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** is_grouplist_in_sudoers
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "my_list.h"

bool is_group_in_sudoers(char *groupname)
{
    FILE *sudoers_file = fopen("/etc/sudoers", "r");
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, sudoers_file) != -1) {
        if (strstr(line, groupname)) {
            free(line);
            fclose(sudoers_file);
            return true;
        }
    }
    free(line);
    fclose(sudoers_file);
    return false;
}

bool is_grouplist_in_sudoers(linked_list_t *group_list)
{
    linked_list_t *temp = group_list;

    while (temp) {
        if (is_group_in_sudoers((char *)(temp->data)))
            return true;
        temp = temp->next;
    }
    return false;
}
