/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** parsing_args
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my_sudo.h"
#include "utils.h"
#include "my_lib.h"

static const char flags_arr[] = {
    'u',
    'g',
    'E',
    's',
    'h',
    '?',
};

bool is_a_flag(char flag, sudo_arguments_t *args)
{
    for (int i = 0; flags_arr[i] != '?'; i++) {
        if (flags_arr[i] == flag)
            return true;
    }
    args->no_argument = true;
    return false;
}

sudo_arguments_t *analyse_sudo_arguments(sudo_arguments_t *args,
    char **av, int index)
{
    for (int i = 0; av[index][i] != '\0'; i++) {
        if (help_flag(args, av[index][i]))
            return NULL;
        if (user_flag(args, av[index][i], av[index + 1]))
            return args;
        if (group_flag(args, av[index][i], av[index + 1]))
            return args;
        shell_flag(args, av[index][i], av[index][i + 1]);
        preserve_environment_flag(args, av[index][i], av[index][i + 1]);
    }
    return args;
}

sudo_arguments_t *parse_arguments(int ac, char **av)
{
    sudo_arguments_t *args = create_sudo_args_struct();

    for (int i = 1; (i < ac) && (args); i++) {
        if (av[i][0] == '-')
            args = analyse_sudo_arguments(args, av, i);
    }
    return args;
}
