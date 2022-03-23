/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** object add set components
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_dico.h"

int object_add_chrono(object_t *object, float seconds,
    float refresh_rate)
{
    sprite_chrono_t *sprite_chrono = malloc(sizeof(sprite_chrono_t));

    if (object == NULL) {
        return BGS_ERR_INPUT;
    } else if (sprite_chrono == NULL) {
        return BGS_ERR_MALLOC;
    }
    sprite_chrono->seconds = seconds;
    sprite_chrono->refresh_rate = refresh_rate;
    return object_add_components(object, sprite_chrono, COMP_CHRONO, &free);
}

int object_add_sprite_health(object_t *object, float life, float max_life,
    void (*dead)(object_t *object, scene_t *scene, window_t *win))
{
    sprite_health_t *sprite_health = NULL;

    if (object->type != SPRITE) {
        return BGS_ERR_INPUT;
    }
    sprite_health = malloc(sizeof(sprite_health_t));
    if (sprite_health == NULL) {
        return BGS_ERR_MALLOC;
    }
    sprite_health->life = life;
    sprite_health->max_life = max_life;
    sprite_health->dead = dead;
    if (life > 0) {
        sprite_health->is_alive = true;
    } else {
        sprite_health->is_alive = false;
    }
    return object_add_components(object, sprite_health, COMP_HEALTH, &free);
}

int object_add_sprite_move(object_t *object, sfVector2f vect)
{
    sprite_move_t *sprite_move = malloc(sizeof(sprite_anim_t));

    if (sprite_move == NULL) {
        return BGS_ERR_MALLOC;
    }
    sprite_move->vect = vect;
    return object_add_components(object, sprite_move, COMP_MOVE, &free);
}

int object_add_sprite_anim(object_t *object, sfIntRect rect)
{
    sprite_anim_t *sprite_anim = NULL;

    if (object->type != SPRITE) {
        return BGS_ERR_INPUT;
    }
    sprite_anim = malloc(sizeof(sprite_anim_t));
    if (sprite_anim == NULL) {
        return BGS_ERR_MALLOC;
    }
    sprite_anim->rect = rect;
    return object_add_components(object, sprite_anim, COMP_ANIM, &free);
}
