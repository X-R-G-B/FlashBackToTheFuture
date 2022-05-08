/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** drop the right item if boss
*/

#include "my_bgs.h"
#include "my_rpg.h"

extern const char is_boss_key[];

void drop_right_item(object_t *obj, window_t *win)
{
    if (obj == NULL || win == NULL) {
        return;
    }
    if (dico_t_get_value(obj->components, is_boss_key) != NULL) {
        get_infinity_86(win);
    } else {
        get_potions(win);
    }
}
