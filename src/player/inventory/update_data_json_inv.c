/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** update_data_json_inv
*/

#include "my_json.h"
#include "my_rpg.h"

void get_potions(window_t *win)
{
    any_t *json = NULL;
    any_t *potions = NULL;

    if (win == NULL) {
        return;
    }
    json = dico_t_get_value(win->components, SAVE);
    potions = get_from_any(json, "d", POTIONS);
    if (potions == NULL || potions->type != INT) {
        return;
    }
    potions->value.i += 1;
    if (write_json(json, SAVE_PATH) != BGS_OK) {
        return;
    }
}

void get_infinity_86(window_t *win)
{
    any_t *json = NULL;
    any_t *key_obj = NULL;

    if (win == NULL) {
        return;
    }
    json = dico_t_get_value(win->components, SAVE);
    key_obj = get_from_any(json, "d", INFINITY_86);
    if (key_obj == NULL || key_obj->type != INT) {
        return;
    }
    key_obj->value.i += 1;
    play_sound(win, INFINITY_86_SOUND);
    if (write_json(json, SAVE_PATH) != BGS_OK) {
        return;
    }
}
