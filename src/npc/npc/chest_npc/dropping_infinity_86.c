/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** dropping infinity 86
*/

#include <stdlib.h>
#include "player.h"
#include "rpg_struct.h"
#include "my_rpg.h"
#include "npc.h"
#include "macro.h"

extern const char infinity_sprite_path[];

extern const char scd_rect_key[];

static const char open_chest_dialog[] = "./assets/data/npc/chest.json";

static const char closed_chest_dialog[] = "./assets/data/npc/closed_chest.json";

static const float drop_infinity_86 = 0.4;

extern const char chest_key[];

extern const char time_key[];

extern const float dropping_86_move_actualisation;

static void check_collision_with_chest(object_t *obj, scene_t *scene)
{
    object_t *chest = dico_t_get_value(obj->components, chest_key);
    sfFloatRect chest_rect = {0};
    sfFloatRect rect = sfSprite_getGlobalBounds(obj->drawable.sprite);

    if (chest == NULL) {
        return;
    }
    chest_rect = sfSprite_getGlobalBounds(chest->drawable.sprite);
    if (sfFloatRect_intersects(&rect, &chest_rect, NULL) == sfTrue) {
        list_add_to_end(scene->to_remove, obj);
    }
}

static void update_dropping_infinity_86(object_t *obj, scene_t *scene,
    window_t *win, float dtime)
{
    float *time = NULL;

    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    time = dico_t_get_value(obj->components, time_key);
    if (time == NULL) {
        return;
    }
    *time += dtime;
    check_collision_with_chest(obj, scene);
    while (*time >= dropping_86_move_actualisation) {
        *time -= dropping_86_move_actualisation;
        obj->bigdata.sprite_bigdata.pos.y -= 1;
        check_collision_with_chest(obj, scene);
    }
}

static void create_dropping_infinity_86(object_t *chest, scene_t *scene,
    player_t *player)
{
    object_t *obj = NULL;
    float *time = NULL;

    obj = create_object(update_dropping_infinity_86, NULL, scene, 0);
    if (object_set_sprite(obj, infinity_sprite_path, (sfIntRect)
        {-1, -1, -1, -1}, player->obj->bigdata.sprite_bigdata.pos) != RET_OK) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {0.2, 0.2});
    obj->components = dico_t_add_data(obj->components, chest_key,
        chest, NULL);
    time = malloc(sizeof(float));
    if (time == NULL) {
        return;
    }
    *time = 0;
    obj->components = dico_t_add_data(obj->components, time_key, time, free);
}

static void update_animation(object_t *obj, scene_t *scene, window_t *win,
    float dtime)
{
    static float time = 0;
    static int counter = 0;
    object_t *chest = NULL;
    player_t *player = NULL;

    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    chest = dico_t_get_value(obj->components, chest_key);
    if (chest == NULL || player == NULL || player->obj == NULL) {
        return;
    }
    time += dtime;
    while (time >= drop_infinity_86 && counter < 5) {
        time -= drop_infinity_86;
        create_dropping_infinity_86(chest, scene, player);
        counter++;
    }
}

void check_have_enough_infinity_86(player_t *player, object_t *chest,
    window_t *win, scene_t *scene)
{
    any_t *stats = dico_t_get_value(player->obj->components, PLAYER_STATS);
    any_t *infinity_86_number = get_from_any(stats, "d", INFINITY_86);
    sfIntRect *rect = NULL;
    object_t *obj = NULL;

    if (infinity_86_number == NULL || infinity_86_number->type != INT) {
        return;
    } else if (infinity_86_number->value.i < 5) {
        add_text_dialog_json(win, closed_chest_dialog, &reaload_dialogs, chest);
        return;
    }
    obj = create_object(update_animation, NULL, scene, 0);
    object_set_custom(obj);
    obj->components = dico_t_add_data(obj->components, chest_key, chest, NULL);
    rect = dico_t_get_value(chest->components, scd_rect_key);
    chest->bigdata.sprite_bigdata.rect = (rect != NULL) ? *rect :
        (sfIntRect) {0, 0, 0, 0};
    reset_86_number(player);
    add_text_dialog_json(win, open_chest_dialog, &reaload_dialogs, chest);
    chest->components = dico_t_rem(chest->components, scd_rect_key);
}
