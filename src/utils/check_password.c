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
#include "my_sudo.h"
#include "utils.h"

int ask_password(char *prompt, const char *password_hash)
{
    char *password = NULL;
    char *hash_result = NULL;
    size_t len = 0;

    if (isatty(fileno(stdin)))
        password = getpass(prompt);
    else
        getline(&password, &len, stdin);
    hash_result = crypt(password, password_hash);
    if ((hash_result != NULL) && strcmp(hash_result, password_hash) == 0) {
        free(prompt);
        return GOOD_PASSWORD;
    }
    free(prompt);
    return TRY_AGAIN;
}

bool check_password(sudo_arguments_t *args, const char *username,
    const char *password_hash, int *attempt)
{
    char *prompt;

    if (!username) {
        *attempt = INCORRECT_USERNAME;
        return false;
    }
    if (args->specific_user_uid == -1) {
        *attempt = INCORRECT_GROUPNAME;
        return false;
    }
    prompt = malloc(sizeof(char) * (strlen("[my_sudo] password for : ")
        + strlen(username) + 2));
    if (is_groupname_in_grouplist(args->group_list, "root"))
        return GOOD_PASSWORD;
    sprintf(prompt, "[my_sudo] password for %s: ", username);
    return ask_password(prompt, password_hash);
}
