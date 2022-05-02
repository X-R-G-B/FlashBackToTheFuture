/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** init_player_scale_handling
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_rpg.h"

const char can_player_up_scale[] = "can_up_scale";
const char can_player_down_scale[] = "can_down_scale";

static int init_player_up_scale(object_t *obj)
{
    bool *can_up_scale = NULL;

    if (obj == NULL || obj->components == NULL) {
        return RET_ERR_INPUT;
    }
    can_up_scale = malloc(sizeof(bool));
    if (can_up_scale == NULL) {
        return RET_ERR_INPUT;
    }
    *can_up_scale = false;
    if (object_add_components(obj, can_up_scale,
            can_player_up_scale, free) != BGS_OK) {
        free(can_up_scale);
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

static int init_player_down_scale(object_t *obj)
{
    bool *can_down_scale = NULL;

    if (obj == NULL || obj->components == NULL) {
        return RET_ERR_INPUT;
    }
    can_down_scale = malloc(sizeof(bool));
    if (can_down_scale == NULL) {
        return RET_ERR_INPUT;
    }
    *can_down_scale = false;
    if (object_add_components(obj, can_down_scale,
            can_player_down_scale, free) != BGS_OK) {
        free(can_down_scale);
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

int init_player_scale_handling(object_t *obj)
{
    if (init_player_up_scale(obj) != RET_OK ||
            init_player_down_scale(obj) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}
