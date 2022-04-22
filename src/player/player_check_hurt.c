/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** player check hurt
*/

#include "ennemies.h"

static bool check_ennemy_col(ennemy_t *ennemy, sfFloatRect player_rect)
{
    sfFloatRect ennemy_rect = {0};

    if (ennemy == NULL) {
        return false;
    }
    ennemy_rect = sfSprite_getGlobalBounds(ennemy->obj->drawable.sprite);
    if (sfFloatRect_intersects(&ennemy_rect, &player_rect, NULL) == sfTrue) {
        return true;
    }
    return false;
}

static sfFloatRect get_player_rect(player_t *player)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(player->obj->drawable.sprite);
    float prev_height = rect.height;

    if (player->state == ATTACKING) {
        return get_attack_hitbox_rect(rect, player);
    }
    rect.height = rect.height * 0.60;
    rect.top += prev_height - rect.height;
    return rect;
}

static void set_hurt(player_t *player)
{
    bool hurt = true;

    set_stop(player);
    player->obj->components = dico_t_add_data(player->obj->components, "hurt",
        ((void *) hurt), NULL);
}

void player_check_hurt(player_t *player, scene_t *scene)
{
    list_ptr_t *ennemy_list = NULL;
    list_t *elem = NULL;
    sfFloatRect rect = {0};

    if (player == NULL || scene == NULL) {
        return;
    }
    rect = get_player_rect(player);
    ennemy_list = dico_t_get_value(scene->components, ENNEMY_LIST);
    if (ennemy_list == NULL) {
        return;
    }
    elem = ennemy_list->start;
    for (int i = 0; i < ennemy_list->len; i++, elem = elem->next) {
        if (check_ennemy_col(elem->var, rect) == true) {
            set_hurt(player);
            return;
        }
    }
}
