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

Test(incorrect_groupname, test_basic)
{
    sudo_arguments_t *args = create_sudo_args_struct();

    cr_assert_eq(incorrect_groupname(args), 84);
}

Test(incorrect_groupname_test, test_basic)
{
    sudo_arguments_t *args = create_sudo_args_struct();

    cr_assert_eq(incorrect_groupname(args), 84);
}

Test(incorrect_password, test_basic)
{
    sudo_arguments_t *args = create_sudo_args_struct();

    cr_assert_eq(incorrect_password(args), 84);
}

Test(incorrect_username_test, test_basic)
{
    sudo_arguments_t *args = create_sudo_args_struct();

    cr_assert_eq(incorrect_username(args), 84);
}

Test(user_flag_test, test_basic)
{
    sudo_arguments_t *args = create_sudo_args_struct();

    cr_assert_eq(user_flag(args, 'u', "root"), true);
}

Test(user_flag_test_bis, test_basic)
{
    sudo_arguments_t *args = create_sudo_args_struct();

    cr_assert_eq(user_flag(args, 'g', "root"), false);
}

Test(user_exist_test, test_basic)
{
    cr_assert_eq(does_user_exist(NULL), false);
}

Test(user_exist_test_bis, test_basic)
{
    cr_assert_eq(does_user_exist("userquiexistepas"), false);
}
