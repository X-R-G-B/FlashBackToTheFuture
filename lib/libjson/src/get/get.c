/*
** EPITECH PROJECT, 2022
** defender
** File description:
** get
*/

#include <stddef.h>
#include "my_strings.h"
#include "my_json.h"

any_t *dico_t_get_any(dico_t *dico, char const *key)
{
    return dico_t_get_value(dico, key);
}

any_t *check_any(any_t *any, char const *format, int i, va_list ap)
{
    any_t *ret_any = NULL;
    int arg = 0;
    char *str_arg = NULL;

    if (any == NULL) {
        return (NULL);
    }
    if (any->type == DICT && format[i] == 'd') {
        str_arg = va_arg(ap, char *);
        ret_any = dico_t_get_any(any->value.dict, str_arg);
    } else if (any->type == ARRAY) {
        arg = va_arg(ap, int);
        ret_any = ((any_t *) get_element_i_var(any->value.array, arg));
    }
    return ret_any;
}

any_t *get_from_any(any_t *any, char const *format, ...)
{
    va_list ap;
    int format_len = 0;

    if (format == NULL) {
        return NULL;
    }
    va_start(ap, format);
    format_len = my_strlen(format);
    for (int i = 0; i < format_len; i++) {
        any = check_any(any, format, i, ap);
    }
    va_end(ap);
    return any;
}
