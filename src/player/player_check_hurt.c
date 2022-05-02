/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** player check hurt
*/

#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include "ennemies.h"
#include "my_bgs.h"
#include "maths_function.h"

static const char DAMMAGE_KEY[] = "dammage";

extern const char data_directions[];

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

static void set_hurt(player_t *player, ennemy_t *ennemy)
{
    bool hurt = true;
    any_t *ennemy_data = dico_t_get_value(ennemy->obj->components, ENNEMY_DATA);
    any_t *dammage = NULL;
    sfVector2f *dirrections = NULL;

    set_stop(player);
    player->obj->components = dico_t_add_data(player->obj->components, "hurt",
        ((void *) hurt), NULL);
    dammage = get_from_any(ennemy_data, "d", DAMMAGE_KEY);
    if (dammage == NULL || dammage->type != FLOAT) {
        return;
    }
    player->life -= dammage->value.f;
    dirrections = malloc(sizeof(sfVector2f));
    if (dirrections == NULL) {
        return;
    }
    fill_get_distance(player->obj->bigdata.sprite_bigdata.pos,
        ennemy->obj->bigdata.sprite_bigdata.pos, dirrections);
    object_add_components(player->obj, dirrections, data_directions, &free);
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
            set_hurt(player, elem->var);
            return;
        }
    }
}
