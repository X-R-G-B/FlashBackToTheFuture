/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** create_nbr_potions_text
*/

#include "my_rpg.h"
#include "my_conversions.h"
#include <stdlib.h>

static const char potions_font_path[]=
    "assets/fonts/Menlo-Regular.ttf";

static const float angle_text = -35.0;

static const int size_text = 80;

const sfVector2f potions_text_pos = {1625.0, 530.0};

extern const int obj_layer;

static int get_potions_nbr(window_t *win)
{
    any_t *player_save = NULL;
    any_t *potions = NULL;

    if (win == NULL) {
        return -1;
    }
    player_save = dico_t_get_value(win->components, SAVE);
    potions = get_from_any(player_save, "d", POTIONS);
    if (potions == NULL) {
        return -1;
    }
    return potions->value.i;
}

static void set_text(object_t *obj)
{
    sfText_setCharacterSize(obj->drawable.text, size_text);
    sfText_setColor(obj->drawable.text, sfBlack);
    sfText_setRotation(obj->drawable.text, angle_text);
}

int create_number_of_potions(scene_t *scene, window_t *win)
{
    object_t *obj = NULL;
    int potions_nbr = get_potions_nbr(win);
    char *potions = NULL;

    if (potions_nbr == -1) {
        return RET_ERR_INPUT;
    }
    potions = my_itoa(potions_nbr);
    obj = create_object(NULL, NULL, scene, obj_layer);
    if (obj == NULL || object_set_text(obj, potions_font_path,
        potions, potions_text_pos) != BGS_OK) {
        free(potions);
        return RET_ERR_MALLOC;
    }
    free(potions);
    set_text(obj);
    if (scene_add_components(scene, obj, POTIONS_TEXT, NULL) != BGS_OK) {
        return RET_ERR_MALLOC;
    }
    return RET_OK;
}
