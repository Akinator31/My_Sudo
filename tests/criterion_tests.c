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
#include "my_lib.h"

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

Test(strdup_test, test_basic)
{
    cr_assert_eq(my_strdup(NULL), NULL);
}

Test(no_arg_test, test_basic)
{
    cr_assert_eq(is_no_arg_error(0), 84);
}

Test(no_arg_test_bi_test_basic_meta, test_basic)
{
    cr_assert_eq(is_no_arg_error(1), 84);
}

Test(group_test, test_basic)
{
    cr_assert_eq(does_group_exist("jesperequetuexistespas"), false);
}

Test(group_test_bis, test_basic)
{
    cr_assert_eq(does_group_exist("root"), true);
}

Test(test_free_2d, test_basic)
{
    char **word_array = my_str_to_word_array("ceci est un test");
    free_2d_array_of_char(word_array);
    word_array = NULL;
    cr_assert_null(word_array);
}

Test(get_uid_test, test_basic)
{
    cr_assert_eq(get_uid_from_user(NULL), 0);
}

Test(fetch_uid_test, test_basic)
{
    cr_assert_eq(fetch_uid_from_user("a b 205"), 205);
}

Test(fetch_group_test, test_basic)
{
    cr_assert_eq(fetch_group_list(NULL), NULL);
}

Test(get_git_test, test_basic)
{
    sudo_arguments_t *args = create_sudo_args_struct();

    cr_assert_eq(display_help_message(args, 0), 0);
}

Test(group_list_test, test_basic)
{
    linked_list_t *test = NULL;

    cr_assert_eq(is_grouplist_in_sudoers(test), false);
}

Test(group_name_in_list_test, test_basic)
{
    linked_list_t *test = NULL;

    cr_assert_eq(is_groupname_in_grouplist(test, NULL), true);
}

Test(group_name_in_list_test_bis, test_basic)
{
    linked_list_t *test = NULL;

    cr_assert_eq(is_groupname_in_grouplist(test, "test"), false);
}

Test(parse_args_test, test_basic)
{
    char **word_array = NULL;

    cr_assert_eq(parse_arguments(0, word_array), NULL);
}
