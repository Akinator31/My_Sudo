/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** username_in_group
*/

#include <string.h>
#include <stdbool.h>
#include "my_list.h"

bool is_groupname_in_grouplist(linked_list_t *group_list, char *groupname)
{
    linked_list_t *temp = group_list;

    if (!groupname)
        return true;
    while (temp) {
        if (!strcmp(groupname, (char *)(temp->data)))
            return true;
        temp = temp->next;
    }
    return false;
}
