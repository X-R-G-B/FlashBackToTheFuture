/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** init_text_hud
*/

#include "my_bgs.h"
#include "macro.h"
#include "my_rpg.h"

extern const sfVector2f life_hud_pos;
extern const sfVector2f energy_hud_pos;

extern const char path_font[];
extern const char life_max_name[];
extern const char energy_max_name[];

static const float padding = 25;

static int init_text_max(object_t *object,
    sfVector2f pos, sfColor color)
{
    if (object == NULL) {
        return RET_ERR_INPUT;
    }
    if (object_set_text(object, path_font, "42", pos) != BGS_OK) {
        return RET_ERR_MALLOC;
    }
    sfText_setColor(object->drawable.text, sfBlack);
    sfText_setOutlineColor(object->drawable.text, color);
    sfText_setOutlineThickness(object->drawable.text, 3.0);
    return RET_OK;
}

static int create_max_life_and_energy(scene_t *scene, object_t **life,
    object_t **energy)
{
    sfVector2f life_text_pos = {0};
    sfVector2f energy_text_pos = {0};

    if (scene == NULL || life == NULL) {
        return RET_ERR_INPUT;
    }
    life_text_pos = (sfVector2f) {life_hud_pos.x + padding,
        life_hud_pos.y - padding};
    energy_text_pos = (sfVector2f) {energy_hud_pos.x - padding,
        energy_hud_pos.y - padding};
    *life = create_object(&update_life_text_hud, NULL, scene, LAYER_HUD);
    *energy = create_object(&update_energy_text_hud, NULL, scene, LAYER_HUD);
    if (init_text_max(*life, life_text_pos, sfRed) != RET_OK ||
            init_text_max(*energy, energy_text_pos, sfGreen) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

static void init_default_txt_values(object_t *life_text_max,
    object_t *energy_text_max, player_t *player)
{
    float clear = 0.0;

    update_text_hud(life_text_max, player, life_max_name, &clear);
    update_text_hud(energy_text_max, player, energy_max_name, &clear);
}

int init_text_hud(window_t *win, scene_t *scene)
{
    object_t *life_text_max = NULL;
    object_t *energy_text_max = NULL;
    player_t *player = NULL;

    if (win == NULL || scene == NULL) {
        return RET_ERR_INPUT;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (create_max_life_and_energy(scene, &life_text_max, &energy_text_max)) {
        return RET_ERR_MALLOC;
    }
    if (add_hud_to_hud_element(win, life_text_max, player) != RET_OK ||
            add_hud_to_hud_element(win, energy_text_max, player) != RET_OK) {
        return RET_ERR_INPUT;
    }
    init_default_txt_values(life_text_max, energy_text_max, player);
    return RET_OK;
}
