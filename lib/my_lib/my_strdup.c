/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** task01
*/

#include <stdlib.h>
#include <string.h>

char *my_strdup(char const *src)
{
    char *result = NULL;
    int i;

    if (!src)
        return NULL;
    result = malloc(sizeof(char) * strlen(src) + 1);
    if (result == NULL)
        return 0;
    for (i = 0; src[i] != '\0'; i++)
        result[i] = src[i];
    result[i] = '\0';
    return result;
}
