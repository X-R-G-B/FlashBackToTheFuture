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
    bool can_up_scale = true;
    dico_t *data = NULL;

    if (obj == NULL || obj->components == NULL) {
        return RET_ERR_INPUT;
    }
    if (object_add_components(obj, (void *) can_up_scale,
            can_player_up_scale, NULL) != BGS_OK) {
        printf("ok\n");
        return RET_ERR_INPUT;
    }
    data = dico_t_get_elem(obj->components, can_player_up_scale);
    if (data == NULL) {
        return RET_ERR_INPUT;
    }
    data->value = (void *) false;
    return RET_OK;
}

static int init_player_down_scale(object_t *obj)
{
    bool can_down_scale = true;
    dico_t *data = NULL;

    if (obj == NULL || obj->components == NULL) {
        return RET_ERR_INPUT;
    }
    if (object_add_components(obj, (void *) can_down_scale,
            can_player_down_scale, NULL) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    data = dico_t_get_elem(obj->components, can_player_up_scale);
    if (data == NULL) {
        return RET_ERR_INPUT;
    }
    data->value = (void *) false;
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
