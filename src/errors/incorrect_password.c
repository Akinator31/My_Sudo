/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** incorrect_password
*/

#include <unistd.h>
#include "my_sudo.h"
#include "utils.h"

int incorrect_password(sudo_arguments_t *args)
{
    write(2, "[my_sudo] 3 incorrect password attempts\n", 41);
    destroy_sudo_args(args);
    return 84;
}
