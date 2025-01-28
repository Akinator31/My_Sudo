/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** incorrect_username
*/

#include <unistd.h>
#include "my_sudo.h"
#include "utils.h"

int incorrect_username(sudo_arguments_t *args)
{
    write(2, "Incorrect username !\n", 22);
    destroy_sudo_args(args);
    return 84;
}
