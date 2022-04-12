/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** increment uid pos
*/

#include "my_rpg.h"

void increment_uid_pos(scene_t *scene, sfVector2f to_add)
{
    list_ptr_t *uid_elements = NULL;
    list_t *elem = NULL;
    object_t *obj = NULL;

    if (scene == NULL) {
        return;
    }
    uid_elements = dico_t_get_value(scene->components, UID_ELEMENTS);
    if (uid_elements == NULL) {
        return;
    }
    elem = uid_elements->start;
    for (int i = 0; i < uid_elements->len; i++, elem = elem->next) {
        obj = elem->var;
        if (obj->type == SPRITE) {
            obj->bigdata.sprite_bigdata.pos.x += to_add.x;
            obj->bigdata.sprite_bigdata.pos.y += to_add.y;
        } else if (obj->type == TEXT) {
            obj->bigdata.text_bigdata.pos.x += to_add.x;
            obj->bigdata.text_bigdata.pos.y += to_add.y;
        }
    }
}
