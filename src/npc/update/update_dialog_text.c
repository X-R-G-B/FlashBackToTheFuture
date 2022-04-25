/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** update text dialog
*/

#include "my_bgs.h"
#include "my_dico.h"
#include "npc.h"
#include <SFML/Graphics/Text.h>
#include <SFML/System/Vector2.h>

static void update_text_display(object_t *obj, const char *string)
{
    sfFloatRect bound = {0};
    sfVector2f center = {0};

    obj->is_visible = true;
    sfText_setString(obj->drawable.text, string);
    bound = sfText_getGlobalBounds(obj->drawable.text);
    center.x = bound.width / 2;
    center.y = bound.height / 2;
    sfText_setOrigin(obj->drawable.text, center);
}

static void update_delta_time(text_dialog_t *text, float dtime)
{
    if (text == NULL) {
        return;
    }
    text->time += dtime;
}

static void update_position(object_t *obj, window_t *win)
{
    const sfView *view = NULL;
    sfVector2f center = {0};

    if (win == NULL) {
        return;
    }
    view = sfRenderWindow_getView(win->win);
    if (view == NULL) {
        return;
    }
    center = sfView_getCenter(view);
    obj->bigdata.text_bigdata.pos.x = center.x + pos_dialog.x;
    obj->bigdata.text_bigdata.pos.y = center.y + pos_dialog.y;
}

void update_text_dialog(object_t *obj, scene_t *scene,
    __attribute((unused)) window_t *win,
    __attribute((unused)) float dtime)
{
    static char *tmp = NULL;
    dialog_manager_t *dialog = NULL;

    if (scene == NULL || obj == NULL || scene->pause == true) {
        return;
    }
    update_position(obj, win);
    dialog = dico_t_get_value(scene->components, compo_dialog);
    if (dialog == NULL || dialog->dialogues == NULL ||
            dialog->dialogues->len <= 0) {
        obj->is_visible = false;
        return;
    }
    if (tmp == dialog->text || dialog->text == NULL) {
        update_delta_time(dialog->dialogues->start->var, dtime);
        return;
    }
    tmp = dialog->text;
    update_text_display(obj, tmp);
}
