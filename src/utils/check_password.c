/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** check_password
*/

#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include "utils.h"

bool check_password(const char *username,
    const char *password_hash, int *attempt)
{
    char *password = NULL;
    char *hash_result = NULL;
    char prompt[strlen("[my_sudo] password for : ") + strlen(username) + 2];

    if (!username) {
        *attempt = INCORRECT_USERNAME;
        return false;
    }
    sprintf(prompt, "[my_sudo] password for %s: ", username);
    password = getpass(prompt);
    hash_result = crypt(password, password_hash);
    if ((hash_result != NULL) && strcmp(hash_result, password_hash) == 0)
        return GOOD_PASSWORD;
    return TRY_AGAIN;
}
