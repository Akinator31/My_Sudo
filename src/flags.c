/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** flags
*/

#include "my_lib.h"
#include "utils.h"

bool help_flag(sudo_arguments_t *args, char character)
{
    if (character == 'h') {
        args->help = 1;
        return true;
    }
    return false;
}

bool user_flag(sudo_arguments_t *args, char character, char *argument)
{
    if (character == 'u') {
        args->specific_user = my_strdup(argument);
        args->start_index += 2;
        return true;
    }
    return false;
}

bool group_flag(sudo_arguments_t *args, char character, char *argument)
{
    if (character == 'g') {
        args->specific_group = my_strdup(argument);
        args->start_index += 2;
        return true;
    }
    return false;
}

void shell_flag(sudo_arguments_t *args, char character, char next_character)
{
    if (character == 's') {
        args->execute_shell = true;
        if (next_character == '\0')
            args->start_index += 1;
    }
}

void preserve_environment_flag(sudo_arguments_t *args, char character,
    char next_character)
{
    if (character == 'E') {
        args->preserve_env = true;
        if (next_character == '\0')
            args->start_index += 1;
    }
}
