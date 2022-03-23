/*
** EPITECH PROJECT, 2022
** prety print
** File description:
** print dico
*/

#include "my_json.h"
#include "my_puts.h"

int prety_print_rec(int fd, any_t *any, int indent);

int close_dico(int fd, int indent, int nb)
{
    for (int i = 0; i < indent - 4; i++) {
        nb += my_putchar(fd, ' ');
    }
    nb += my_putstr(fd, "}");
    return nb;
}

int do_print_dico(int fd, any_t *any, int indent)
{
    int nb = 0;
    dico_t *elem = any->value.dict;

    nb += my_putstr(fd, "{\n");
    do {
        for (int i = 0; i < indent; i++) {
            nb += my_putchar(fd, ' ');
        }
        my_putchar(fd, '"');
        my_putstr(fd, elem->key);
        my_putchar(fd, '"');
        nb += my_putstr(fd, ": ");
        nb += prety_print_rec(fd, elem->value, indent + 4);
        if (elem->next != any->value.dict) {
            nb += my_putchar(fd, ',');
        }
        nb += my_putchar(fd, '\n');
        elem = elem->next;
    } while (elem != any->value.dict);
    return close_dico(fd, indent, nb);
}
