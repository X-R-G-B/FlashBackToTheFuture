/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destoy ennemy
*/

#include <stdlib.h>
#include "ennemies.h"

void destroy_ennemy(ennemy_t *ennemy, scene_t *scene)
{
    list_ptr_t *ennemy_list = NULL;

    if (ennemy == NULL  || ennemy->obj == NULL || scene == NULL) {
        return;
    }
    ennemy_list = dico_t_get_value(scene->components, ENNEMY_LIST);
    if (ennemy_list == NULL) {
        return;
    }
    printf("oui\n");
    //list_add_to_end(scene->to_remove, ennemy->obj);
    check_list(ennemy_list, ennemy);
    free(ennemy);
}
