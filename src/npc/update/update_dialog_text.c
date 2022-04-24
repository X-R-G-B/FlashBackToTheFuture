/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** update text dialog
*/

#include "my_bgs.h"
#include "my_dico.h"
#include "npc.h"

void update_text_dialog(object_t *obj, scene_t *scene,
    __attribute((unused)) window_t *win,
    __attribute((unused)) float dtime)
{
    static char *tmp = NULL;
    dialog_manager_t *dialog = NULL;

    if (scene == NULL || obj == NULL || scene->pause == true) {
        return;
    }
    dialog = dico_t_get_value(scene->components, compo_dialog);
    if (dialog == NULL || dialog->dialogues == NULL ||
            dialog->dialogues->len <= 0) {
        obj->is_visible = false;
        return;
    }
    if (tmp == dialog->text || tmp == NULL) {
        return;
    }
    obj->is_visible = true;
    tmp = dialog->text;
    sfText_setString(obj->drawable.text, tmp);
}
