/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init and update the making of
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_rpg.h"

static const char index_image_compo[] = "index_image_compo";

int init_making_of(scene_t *scene)
{
    int *index_image = NULL;

    if (scene == NULL) {
        return (RET_ERR_INPUT);
    }
    index_image = malloc(sizeof(int));
    if (scene_add_components(scene, index_image, index_image_compo, free)) {
        return (RET_ERR_MALLOC);
    }
    return (RET_OK);
}
