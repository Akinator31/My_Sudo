/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** incorrect_groupname
*/

#include <unistd.h>
#include "my_sudo.h"
#include "utils.h"

int incorrect_groupname(sudo_arguments_t *args)
{
    write(2, "Incorrect groupname !\n", 23);
    destroy_sudo_args(args);
    return 84;
}
