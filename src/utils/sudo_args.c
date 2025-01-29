/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** destroy_sudo_args
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_sudo.h"

sudo_arguments_t *create_sudo_args_struct(void)
{
    sudo_arguments_t *args = malloc(
        sizeof(sudo_arguments_t));

    args->group_list = NULL;
    args->start_index = 1;
    args->execute_shell = false;
    args->preserve_env = false;
    args->specific_user = NULL;
    args->specific_group = NULL;
    args->help = 0;
    args->incorrect_groupname = 0;
    args->owner_username = NULL;
    return args;
}

void destroy_sudo_args(sudo_arguments_t *args)
{
    if (args->specific_group)
        free(args->specific_group);
    if (args->specific_user)
        free(args->specific_user);
    free(args);
}

void print_sudo_args(sudo_arguments_t *args)
{
    if (args->specific_user)
        printf("User argument : %s\n", args->specific_user);
    if (args->specific_group)
        printf("Group argument : %s\n", args->specific_group);
    printf("Preserve env : %d\n", args->preserve_env);
    printf("Request shell : %d\n", args->execute_shell);
}
