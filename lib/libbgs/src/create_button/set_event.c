/*
** EPITECH PROJECT, 2022
** bgs button generator
** File description:
** set event
*/

#include "my_strings.h"
#include "my_bgs_button_generator.h"

static int set_hover_event(object_t *obj, char *txt)
{
    int on = 0;
    int off = 0;

    for (int i = 1; str_on_hover[i] != NULL && on == 0; i++) {
        if (my_strcmp(txt, str_on_hover[i]) == 1) {
            on = i;
        }
    }
    for (int i = 1; str_off_hover[i - 1] != NULL && off == 0; i++) {
        if (my_strcmp(txt, str_off_hover[i - 1]) == 1) {
            off = i;
        }
    }
    if (create_event(on_hover[on], true, obj, off_hover[off]) == NULL) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}

int set_event(object_t *object, dico_t *dico)
{
    any_t *txt = dico_t_get_any(dico, "text");
    void (*on)(object_t *, scene_t *, window_t *, set_event_t *) = NULL;
    void (*off)(object_t *, scene_t *, window_t *, set_event_t *) = NULL;

    if (txt == NULL || txt->type != STR) {
        return BGS_ERR_INPUT;
    }
    for (int i = 0; str_on_click[i] != NULL && on == NULL; i++) {
        if (my_strcmp(txt->value.str, str_on_click[i]) == 0) {
            on = on_click[i];
        }
    }
    for (int i = 0; str_off_click[i] != NULL && off == NULL; i++) {
        if (my_strcmp(txt->value.str, str_off_click[i]) == 0) {
            off = off_click[i];
        }
    }
    return (event_add_node(create_event(on, true, object, off),
        (node_params_t) {sfMouseLeft, sfKeyA, MOUSE}) == BGS_OK) ?
        set_hover_event(object, txt->value.str) : 1;
}
