/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** my_exec
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my_sudo.h"

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
    if (!args[0])
        return 84;
    return execvp(args[0], args);
}
