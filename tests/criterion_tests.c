/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-mysudo-pavel.de-wavrechin
** File description:
** criterion_tests
*/

#include <criterion/criterion.h>
#include "my_sudo.h"
#include "utils.h"
#include "errors.h"

Test(incorrect_username, test_basic)
{
    sudo_arguments_t *args = create_sudo_args_struct();

    cr_assert_eq(incorrect_groupname(args), 84);
}
