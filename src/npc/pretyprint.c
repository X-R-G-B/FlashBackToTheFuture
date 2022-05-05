/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** pretyprint some text
*/

#include <stdlib.h>
#include "my_strings.h"

int count_token(const char *str, const char *token)
{
    int nb = 0;

    if (str == NULL || token == NULL) {
        return (0);
    }
    for (int i = 0; i < my_strlen(str); i++) {
        if (my_strstartswith(str + i, token) == 1) {
            nb += 1;
            i += my_strlen(token) - 1;
        }
    }
    return (nb);
}

static char *itter_to_str(const char *str, int nb_malloc, char *new)
{
    int index = 0;
    int i = 0;

    for (; i < my_strlen(str) && index < nb_malloc; i++) {
        if (my_strstartswith(str + i, "\\n") == 1) {
            new[index++] = '\n';
            i += 1;
        } else {
            new[index++] = str[i];
        }
    }
    return (new);
}

char *parseprety(const char *str)
{
    int nb_malloc = 0;
    char *new = NULL;

    if (str == NULL) {
        return (NULL);
    }
    nb_malloc = my_strlen(str) - count_token(str, "\\n");
    new = my_calloc(sizeof(char) * (nb_malloc + 2));
    if (new == NULL) {
        return (NULL);
    }
    itter_to_str(str, nb_malloc, new);
    return (new);
}

char *parseprety_free(char *str)
{
    char *new = NULL;

    new = parseprety(str);
    if (new == NULL) {
        return (str);
    }
    free(str);
    return (new);
}
