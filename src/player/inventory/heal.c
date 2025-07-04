/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** heal
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_conversions.h"
#include "macro.h"
#include "audio.h"
#include "player.h"

static const char use_potion_file[] = "./assets/data/pop_text/use_potion.json";

extern const char stats_path_key[];

void modif_potion_value(window_t *win, int nbr_potions, bool click)
{
    scene_t *scene = NULL;
    object_t *obj = NULL;
    char *text = NULL;

    if (win == NULL) {
        return;
    }
    scene = dico_t_get_value(win->scenes, INV_SCENE);
    if (scene == NULL) {
        return;
    }
    obj = dico_t_get_value(scene->components, POTIONS_TEXT);
    if (obj == NULL) {
        return;
    }
    create_pop_text((click == true) ? scene : NULL, use_potion_file,
        obj->bigdata.sprite_bigdata.pos, "-1", win->path_root);
    text = my_itoa(nbr_potions);
    sfText_setString(obj->drawable.text, text);
    free(text);
}

static void used_potion(window_t *win)
{
    any_t *inv_data = NULL;
    any_t *potions = NULL;
    player_t *player = dico_t_get_value(win->components, PLAYER);
    scene_t *scene = dico_t_get_value(win->scenes, win->current_scene);

    if (scene == NULL || player == NULL || player->obj == NULL) {
        return;
    }
    inv_data = dico_t_get_any(player->obj->components, PLAYER_STATS);
    potions = get_from_any(inv_data, "d", POTIONS);
    if (potions == NULL) {
        return;
    }
    if (potions->value.i > 0) {
        potions->value.i -= 1;
        play_sound(win, CONSUM_CAN_SOUND);
        modif_potion_value(win, potions->value.i, true);
        write_json(inv_data, dico_t_get_value(player->obj->components,
            stats_path_key));
    }
}

static float get_max_life(player_t *player)
{
    any_t *player_stats = NULL;
    any_t *max_life = NULL;

    if (player == NULL || player->obj->components == NULL) {
        return RET_ERR_INPUT;
    }
    player_stats = dico_t_get_any(player->obj->components, PLAYER_STATS);
    max_life = get_from_any(player_stats, "d", MAX_LIFE);
    if (max_life == NULL) {
        return RET_ERR_MALLOC;
    }
    return max_life->value.f;
}

static void is_above_max_health(player_t *player, float max_life)
{
    if (player->life >= max_life) {
        player->life = max_life;
    }
}

void heal(window_t *win)
{
    player_t *player = NULL;
    float max_life = 0;

    if (win == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->obj == NULL) {
        return;
    }
    max_life = get_max_life(player);
    if (max_life == RET_ERR_INPUT || max_life == RET_ERR_MALLOC) {
        return;
    }
    if (player->life < max_life) {
        used_potion(win);
    }
    player->life += 100.0;
    is_above_max_health(player, max_life);
}
