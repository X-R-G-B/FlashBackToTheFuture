/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** ennemy check hurt
*/

#include <stdlib.h>
#include "macro.h"
#include "ennemies.h"
#include "maths_function.h"

static const char pop_text_file[] = "./assets/data/pop_text/ennemy_hurt.json";
static const char attack_key[] = "attack";
static const char sword_key[] = "sword";
static const char dammage_key[] = "dammage";
static const char dammage_hitbox_key[] = "dammage hitbox";

static any_t *get_current_sword_pos(player_t *player)
{
    any_t *data = NULL;

    if (player == NULL || player->obj == NULL) {
        return NULL;
    }
    data = dico_t_get_value(player->obj->components, PLAYER_DATA);
    if (data == NULL) {
        return NULL;
    }
    return get_from_any(data, "dddaa", attack_key, sword_key,
        dammage_hitbox_key, player->dir, get_rect_id(data, player));
}

static sfVector2f get_pos(any_t *current_sword_pos, int id,
    sfFloatRect player_rect)
{
    any_t *pos = get_from_any(current_sword_pos, "a", id);
    int *arr = NULL;
    sfVector2f vect = {0};

    if (pos == NULL || pos->type != ARRAY || pos->value.array->len != 2) {
        return (sfVector2f) {-1, -1};
    }
    arr = get_any_int_array(pos);
    if (arr == NULL) {
        return (sfVector2f) {-1, -1};
    }
    vect = (sfVector2f) {arr[0] + player_rect.left, arr[1] + player_rect.top};
    free(arr);
    return vect;
}

static void set_hurt(ennemy_t *ennemy, player_t *player, sfVector2f impact,
    window_t *win)
{
    bool hurt = true;
    any_t *data = dico_t_get_value(player->obj->components, PLAYER_DATA);
    any_t *dammage = NULL;

    dammage = get_from_any(data, "ddd", attack_key, sword_key, dammage_key);
    add_gore_sword(win, impact);
    if (dammage == NULL || dammage->type != FLOAT) {
        return;
    }
    create_stat_pop_text_from_window(win, (int) (dammage->value.f * -1),
        pop_text_file, impact);
    if (ennemy->state == ATTACKING) {
        ennemy->state = STOP;
        ennemy->delta_time = 0;
    }
    ennemy->life -= dammage->value.f;
    ennemy->obj->components = dico_t_add_data(ennemy->obj->components, hurt_key,
        (void *) hurt, NULL);
}

static void ennemy_check_collision(ennemy_t *ennemy, window_t *win)
{
    player_t *player = dico_t_get_value(win->components, PLAYER);
    any_t *current_sword_pos = get_current_sword_pos(player);
    sfVector2f fst_pos = {-1, -1};
    sfVector2f scd_pos = {-1, -1};
    sfFloatRect player_rect = {0};

    if (current_sword_pos == NULL || current_sword_pos->type != ARRAY ||
        current_sword_pos->value.array->len != 2) {
        return;
    }
    player_rect = sfSprite_getGlobalBounds(player->obj->drawable.sprite);
    fst_pos = get_pos(current_sword_pos, 0, player_rect);
    scd_pos = get_pos(current_sword_pos, 1, player_rect);
    if (fst_pos.x < 0 || scd_pos.x < 0) {
        return;
    } else if (rect_contains_segment(sfSprite_getGlobalBounds(
        ennemy->obj->drawable.sprite), fst_pos, scd_pos) == true) {
        set_hurt(ennemy, player, scd_pos, win);
    }
}

bool ennemy_check_hurt(ennemy_t *ennemy, scene_t *scene, window_t *win,
    float dtime)
{
    bool hurt = false;
    player_t *player = NULL;

    if (ennemy == NULL || ennemy->obj == NULL || scene == NULL || win == NULL) {
        return false;
    }
    player = dico_t_get_value(win->components, PLAYER);
    hurt = (bool) dico_t_get_value(ennemy->obj->components, hurt_key);
    if (hurt == true) {
        ennemy_update_hurt(ennemy, dtime, win, scene);
    } else if (player != NULL && player->state == ATTACKING) {
        ennemy_check_collision(ennemy, win);
    }
    return hurt;
}
