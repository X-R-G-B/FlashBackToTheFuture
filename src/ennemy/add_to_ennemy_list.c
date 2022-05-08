/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** add ennemy to ennemy list
*/

#include "ennemies.h"
#include "main_menu.h"
#include "macro.h"

int add_to_ennemy_list(ennemy_t *ennemy, scene_t *scene)
{
    list_ptr_t *ennemy_list = NULL;

    if (ennemy == NULL || scene == NULL) {
        return RET_ERR_INPUT;
    }
    ennemy_list = dico_t_get_value(scene->components, ENNEMY_LIST);
    if (ennemy_list == NULL) {
        ennemy_list = list_create();
        if (ennemy_list == NULL || scene_add_components(scene, ennemy_list,
            ENNEMY_LIST, free_pop_up) != RET_OK) {
            return RET_ERR_MALLOC;
        }
    }
    list_add_to_end(ennemy_list, ennemy);
    return RET_OK;
}
