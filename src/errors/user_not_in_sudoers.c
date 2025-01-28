/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** user_not_in_sudoers
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_sudo.h"
#include "utils.h"

int user_not_in_sudoers(char *username, char *groupname)
{
    char *prompt = malloc(sizeof(char) * (strlen(" is not in the"
        "sudoers file\n") + strlen(username) + 2));

    sprintf(prompt, "%s is not in the sudoers file\n", username);
    write(2, prompt, strlen(prompt));
    free(prompt);
    free(username);
    free(groupname);
    return 84;
}
