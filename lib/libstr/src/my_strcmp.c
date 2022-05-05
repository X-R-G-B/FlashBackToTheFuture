/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** compare two str an return 0 if eq
*/

#include "my_macro.h"
#include "my_strings.h"

/**
** @brief compare s1 and s2 char per char
** @param s1
** @param s2
** @return 0 if s1 equal s2; otherwise the difference between s1[x] and s2[x]
**/
int my_strcmp(char const *s1, char const *s2)
{
    char a;
    char b;
    int const lengths[2] = {my_strlen(s1), my_strlen(s2)};
    int sub = 0;
    int const max = MAX(lengths[0], lengths[1]);

    if (lengths[0] == -1 || lengths[1] == -1) {
        return (84);
    }
    for (int i = 0; sub == 0 && i < max; i++) {
        a = (i >= lengths[0]) ? '\0' : s1[i];
        b = (i >= lengths[1]) ? '\0' : s2[i];
        sub = a - b;
    }
    return (sub);
}
