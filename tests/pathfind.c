/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** test pathfind
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include "my_wordarray.h"
#include "ennemy_pathfind.h"

Test(init_pathfind, null_array)
{
    char **array = NULL;
    pathfind_t *path = NULL;

    path = init_pathfind(array, '1', '2');
    cr_assert_eq(path, NULL);
}

Test(init_pathfind, end_zero)
{
    char *array[] = {"coucou", "salut", NULL};
    pathfind_t *path = NULL;

    path = init_pathfind(array, '\0', '1');
    cr_assert_eq(path, NULL);
}

Test(init_pathfind, start_zero)
{
    char *array[] = {"coucou", "salut", NULL};
    pathfind_t *path = NULL;

    path = init_pathfind(array, '1', '\0');
    cr_assert_eq(path, NULL);
}

Test(init_pathfind, test_not_null)
{
    char *array[] = {
        "000000000",
        "00XXXX000",
        "00X000000",
        "00X00E000",
        "000000000",
        NULL
    };
    pathfind_t *path = NULL;

    path = init_pathfind(array, 'E', 'X');
    cr_assert_neq(path, NULL);
    cr_assert_neq(path->map, NULL);
    my_wordarray_free(path->map);
    free(path);
}
