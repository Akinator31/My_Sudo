/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** my_exec
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_sudo.h"

extern char **environ;

void my_exec(sudo_arguments_t *sudo_params, char **args)
{
    if (!sudo_params->preserve_env)
        environ = NULL;
    if (sudo_params->specific_user)
        setuid(sudo_params->uid);
    execvp(args[0], args);
}
