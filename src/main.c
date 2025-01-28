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
    char *group = get_gid(arguments);
    char *user_password = get_hashed_password(username);
    int attempts = 1;
    char **args = &av[arguments->start_index];

    while (check_password(username, user_password, &attempts)
        != GOOD_PASSWORD && attempts < 3) {
        attempts++;
        printf("Sorry, try again\n");
    }
    if (errors_manager(arguments, group, attempts) == 84)
        return 84;
    if (check_user_permissions(username, group)) {
        my_exec(arguments, args);
        return 0;
    }
    return user_not_in_sudoers(username, group);
}

int main(int ac, char **av)
{
    sudo_arguments_t *args = NULL;

    if (ac < 2)
        return 84;
    args = parse_arguments(ac, av);
    if (!args)
        return 84;
    if (args->help)
        return display_help_message(args);
    return my_sudo(av, args);
}
