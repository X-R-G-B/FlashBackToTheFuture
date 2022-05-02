/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** check drop
*/

#include <stdlib.h>
#include "macro.h"
#include "ennemies.h"
#include "maths_function.h"

static const char drop_rate_key[] = "drop rate";

static const char item_sprite_path[] = "./assets/image/item/86.png";

static bool check_drop_chance(ennemy_t *ennemy)
{
    any_t *ennemy_data = NULL;
    any_t *drop_rate = NULL;

    if (ennemy == NULL || ennemy->obj == NULL) {
        return false;
    }
    ennemy_data = dico_t_get_value(ennemy->obj->components, ENNEMY_DATA);
    drop_rate = get_from_any(ennemy_data, "d", drop_rate_key);
    if (drop_rate == NULL || drop_rate->type != FLOAT) {
        return false;
    }
    if (randomise(0, 100) <= drop_rate->value.f) {
        return true;
    }
    return false;
}

static void update_86(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) float dtime)
{
    player_t *player = NULL;
    sfFloatRect player_rect = {0};
    sfFloatRect obj_rect = {0};

    if (obj == NULL || obj->type != SPRITE || scene == NULL || win == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return;
    }
    player_rect = sfSprite_getGlobalBounds(player->obj->drawable.sprite);
    obj_rect = sfSprite_getGlobalBounds(obj->drawable.sprite);
    if (sfFloatRect_intersects(&player_rect, &obj_rect, NULL) == sfTrue) {
        list_add_to_end(scene->to_remove, obj);
        get_potions(win);
    }
}

void check_drop(ennemy_t *ennemy, scene_t *scene)
{
    if (check_drop_chance(ennemy) == false) {
        return;
    }
    object_set_sprite(create_object(update_86, NULL, scene, LAYER_ENNEMY),
        item_sprite_path, (sfIntRect) {-1, -1, -1, -1},
        ennemy->obj->bigdata.sprite_bigdata.pos);
}
