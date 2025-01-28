/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** help_message
*/

#include <stdio.h>
#include "my_sudo.h"
#include "utils.h"

int display_help_message(sudo_arguments_t *args)
{
    if (args)
        destroy_sudo_args(args);
    printf("usage: ./my_sudo -h\n");
    printf("usage: ./my_sudo [-ugEs] [command [args ...]]\n");
    return 0;
}
