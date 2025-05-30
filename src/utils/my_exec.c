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
#include "errors.h"

extern char **environ;

int my_exec(sudo_arguments_t *sudo_params, char **args)
{
    if (!sudo_params->preserve_env)
        environ = NULL;
    if (sudo_params->specific_user) {
        setuid(sudo_params->specific_user_uid);
        seteuid(sudo_params->specific_user_uid);
    }
    if (!sudo_params->specific_user) {
        setuid(0);
        seteuid(0);
    }
    if (!sudo_params->specific_group) {
        setgid(0);
        setegid(0);
    }
    if (!args[0])
        return display_help_message(sudo_params, 84);
    setgroups(0, NULL);
    return execvp(args[0], args);
}
