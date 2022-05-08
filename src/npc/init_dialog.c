/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init dialog to the scene
*/

#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "macro.h"
#include "my_dico.h"
#include "my_rpg.h"
#include "npc.h"

static const char path_dialog_img[] = "./assets/image/npc/dialog_box.png";
static const sfIntRect rect_dialog = {-1, -1, -1, -1};
const sfVector2f pos_dialog = {0, 300};

const char path_font[] = "./assets/fonts/Menlo-Regular.ttf";
const sfVector2f pos_text = {0, 470};

const char compo_dialog[] = "componente dialog";

static dialog_manager_t *create_dialog_manager_t(void)
{
    dialog_manager_t *new = NULL;

    new = malloc(sizeof(dialog_manager_t));
    if (new == NULL) {
        return (NULL);
    }
    new->dialogues = list_create();
    if (new->dialogues == NULL) {
        free(new);
        return (NULL);
    }
    new->text = NULL;
    return (new);
}

static void destroy_dialog_manager_t(void *dialog_void)
{
    dialog_manager_t *dialog = dialog_void;
    list_t *list = NULL;

    if (dialog_void == NULL) {
        return;
    }
    list = (dialog->dialogues != NULL) ? dialog->dialogues->start : NULL;
    for (int i = 0; dialog->dialogues != NULL && i < dialog->dialogues->len;
            i++) {
        free(((text_dialog_t *) list->var)->str);
        free(list->var);
        list = list->next;
    }
    free_list(dialog->dialogues);
    free(dialog);
}

static object_t *create_dialog_obj(scene_t *scene, list_ptr_t *list)
{
    object_t *dialog = NULL;
    object_t *text = NULL;

    dialog = create_object(&update_dialog, NULL, scene, LAYER_MENUS);
    if (object_set_sprite(dialog, path_dialog_img, rect_dialog,
            pos_dialog) != BGS_OK) {
        return (NULL);
    }
    dialog->is_visible = false;
    list_add_to_end(list, dialog);
    text = create_object(update_text_dialog, NULL, scene, LAYER_BUTTON);
    if (object_set_text(text, path_font, "", pos_text) != BGS_OK) {
        return (NULL);
    }
    text->is_visible = false;
    list_add_to_end(list, text);
    return (dialog);
}

static int add_component(window_t *win, dialog_manager_t *comp,
    object_t *dialog)
{
    if (dialog == NULL) {
        return (RET_ERR_INPUT);
    }
    if (window_add_component(win, comp, compo_dialog,
        &destroy_dialog_manager_t) != BGS_OK) {
        destroy_dialog_manager_t(comp);
        return (RET_OK);
    }
    add_event_continue_to_dialog(dialog);
    add_event_quit_to_dialog(dialog);
    return (RET_OK);
}

int init_dialog(scene_t *scene, window_t *win)
{
    dialog_manager_t *comp = NULL;
    list_ptr_t *list_elem = NULL;

    if (scene == NULL) {
        return (RET_ERR_INPUT);
    }
    comp = create_dialog_manager_t();
    if (comp == NULL) {
        return (RET_ERR_MALLOC);
    }
    list_elem = dico_t_get_value(win->components, HUD_ELEMENTS);
    if (add_component(win, comp, create_dialog_obj(scene, list_elem)) !=
            RET_OK) {
        return (RET_ERR_MALLOC);
    }
    return (RET_OK);
}
