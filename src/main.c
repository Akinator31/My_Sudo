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
    char *user_password = get_hashed_password(arguments->owner_username);
    int attempts = 1;
    char **args = &av[arguments->start_index];

    while (check_password(arguments, arguments->owner_username,
        user_password, &attempts)
        != GOOD_PASSWORD && attempts < 3) {
        attempts++;
        printf("Sorry, try again\n");
    }
    if (errors_manager(arguments, attempts) == 84)
        return 84;
    if (check_user_permissions(arguments->owner_username,
        arguments->group_list))
        return my_exec(arguments, args);
    return user_not_in_sudoers(arguments->owner_username);
}

int main(int ac, char **av)
{
    sudo_arguments_t *args = NULL;

    args = parse_arguments(ac, av);
    if (!args)
        return display_help_message(args, 84);
    args->owner_username = get_owner_username();
    args->group_list = fetch_group_list(args->owner_username);
    args->specific_user_uid = get_uid_from_user(args->specific_user);
    if (args->help)
        return display_help_message(args, 0);
    if (!args->owner_username)
        return 84;
    if (args->incorrect_groupname)
        return incorrect_groupname(args);
    if (args->incorrect_username)
        return incorrect_username(args);
    if (is_groupname_in_grouplist(args->group_list, args->specific_group)
        || is_grouplist_in_sudoers(args->group_list))
        return my_sudo(av, args);
    return 84;
}
