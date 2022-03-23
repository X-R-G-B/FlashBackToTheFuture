/*
** EPITECH PROJECT, 2022
** libjson
** File description:
** prety print a any_t json
*/

#include <stddef.h>
#include "my_puts.h"
#include "my_dico.h"
#include "my_json.h"
#include "list.h"

int prety_print_rec(int fd, any_t *any, int indent);
int do_print_dico(int fd, any_t *any, int indent);

static int do_print_array(int fd, any_t *any, int indent)
{
    int nb = 0;
    list_t *elem;

    nb += my_putchar(fd, '[');
    elem = any->value.array->start;
    for (int i = 0; i < any->value.array->len; i++, elem = elem->next) {
        nb += prety_print_rec(fd, elem->var, indent);
        if (i != any->value.array->len - 1) {
            nb += my_putstr(fd, ", ");
        }
    }
    nb += my_putstr(fd, "]");
    return (nb);
}

int my_putfloat(int fd, float val)
{
    int entire_parts = (int) val;
    int nb = 0;
    int float_parts = (val - entire_parts) * 1000000;

    nb += my_putnbr(fd, entire_parts);
    nb += my_putchar(fd, '.');
    nb += my_putnbr(fd, float_parts);
    return (nb);
}

int prety_print_rec(int fd, any_t *any, int indent)
{
    int nb = 0;

    switch (any->type) {
        case DICT:
            nb += do_print_dico(fd, any, indent);
            break;
        case ARRAY:
            nb += do_print_array(fd, any, indent);
            break;
        case STR:
            nb += my_printf(fd, "\"%s\"", any->value.str);
            break;
        case INT:
            nb += my_putnbr(fd, any->value.i);
            break;
        case FLOAT:
            nb += my_putfloat(fd, any->value.f);
            break;
    }
    return (nb);
}

int prety_print(any_t *any, int fd)
{
    int ret = 0;

    if (any == NULL) {
        return (0);
    }
    ret = prety_print_rec(fd, any, 4);
    my_putchar(fd, '\n');
    return ret;
}
