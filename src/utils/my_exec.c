/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** my_exec
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <grp.h>
#include "my_sudo.h"
#include "utils.h"

extern char **environ;

int my_exec(sudo_arguments_t *sudo_params, char **args)
{
    if (!sudo_params->preserve_env)
        environ = NULL;
    if (sudo_params->specific_user)
        setuid(sudo_params->specific_user_uid);
    if (!sudo_params->specific_user)
        setuid(0);
    if (!sudo_params->specific_group)
        setgid(0);
    if (!args[0]) {
        free(sudo_params->specific_user);
        free(sudo_params->owner_username);
        clear_list_and_data(sudo_params->group_list, &free);
        free(sudo_params);
        return 84;
    }
    free(sudo_params->owner_username);
    clear_list_and_data(sudo_params->group_list, &free);
    free(sudo_params);
    setgroups(0, NULL);
    return execvp(args[0], args);
}
