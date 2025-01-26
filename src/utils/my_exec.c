/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** my_exec
*/

#include <unistd.h>

extern char **environ;

void my_exec(char **args)
{
    execvp(args[0], args);
}
