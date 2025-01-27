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
#include "my_sudo.h"

int my_sudo(char **av, sudo_arguments_t *arguments)
{
    char *username = get_uid(arguments);
    char *user_password = get_hashed_password(username);
    int attempts = 1;
    char **args = &av[arguments->start_index];

    while (check_password(username, user_password)
        != GOOD_PASSWORD && attempts < 3) {
        attempts++;
        printf("Sorry, try again\n");
    }
    if (attempts == 3)
        return incorrect_password();
    if (check_user_permissions(username)) {
        my_exec(arguments, args);
        return 0;
    }
    printf("%s is not in the sudoers file\n", username);
    return 84;
}

int main(int ac, char **av)
{
    sudo_arguments_t *args = parse_arguments(ac, av);

    if (args->no_argument | !args)
        return 84;
    if (!args || ac < 2)
        return display_help_message();
    my_sudo(av, args);
}
