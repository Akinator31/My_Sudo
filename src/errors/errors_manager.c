/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** errors_manager
*/

#include "my_sudo.h"
#include "utils.h"
#include "errors.h"

int errors_manager(sudo_arguments_t *args, int attempts)
{
    if (attempts == INCORRECT_USERNAME)
        return incorrect_username(args);
    if (attempts == 3)
        return incorrect_password(args);
    if (attempts == INCORRECT_GROUPNAME)
        return incorrect_groupname(args);
    return 0;
}
