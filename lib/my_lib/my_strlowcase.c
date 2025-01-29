/*
** EPITECH PROJECT, 2024
** my_strlowcase.c
** File description:
** task09
*/

char *my_strlowcase(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A') && (str[i] <= 'Z'))
            str[i] += 32;
    }
    return str;
}
