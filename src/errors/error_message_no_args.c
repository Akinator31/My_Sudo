/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** error_message_no_args
*/

#include <stdio.h>

int is_no_arg_error(int ac)
{
    if (ac == 1) {
        printf("usage: ./my_sudo -h\n");
        printf("usage: ./my_sudo [-ugEs] [command [args ...]]\n");
    }
    return 84;
}
