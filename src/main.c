/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "my_lib.h"
#include "utils.h"
#include "errors.h"

static const char flags_arr[] = {
    'h',
    'u',
    'g',
    'E',
    's',
};

int main(int ac, char **av)
{
    char *username = get_uid();
    char *user_password = get_hashed_password(username);
    int attempts = 1;
    char **args = &av[1];

    while (check_password(username, user_password)
        != GOOD_PASSWORD && attempts < 3) {
        attempts++;
        printf("Sorry, try again\n");
    }
    if (attempts == 3)
        return incorrect_password();
    if (check_user_permissions(username)) {
        my_exec(args);
        return 0;
    }
    printf("%s is not in the sudoers file\n", username);
    return 84;
}
