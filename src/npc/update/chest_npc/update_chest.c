/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update chest
*/

#include <stdlib.h>
#include "npc.h"
#include "macro.h"
#include "my_rpg.h"

extern const char npc_path_key[];

static const char check_into_chest_json[] =
        "./assets/data/npc/check_into_chest.json";

static const char sprite_path_key[] = "sprite path";

static const char chest_key[] = "chest";

extern const char rect_key[];

static const char closed_chest_dialog[] = "./assets/data/npc/closed_chest.json";

extern const char infinity_sprite_path[];

static const char open_chest_dialog[] = "./assets/data/npc/chest.json";

static const float drop_infinity_86 = 0.4;

static const char time_key[] = "time";

static const float dropping_86_move_actualisation = 0.003;

static const char scd_rect_key[] = "scd rect";

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

static void check_have_enough_infinity_86(player_t *player, object_t *chest,
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
    if (rect == NULL) {
        return;
    }
    chest->bigdata.sprite_bigdata.rect = *rect;
    add_text_dialog_json(win, open_chest_dialog, &reaload_dialogs, chest);
    chest->components = dico_t_rem(chest->components, scd_rect_key);
}

static void update_chest(object_t *obj, scene_t *scene, window_t *win,
    float dtime)
{
    player_t *player = NULL;
    sfFloatRect player_rect = {0};
    sfFloatRect chest_rect = {0};

    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    chest_rect = sfSprite_getGlobalBounds(obj->drawable.sprite);
    chest_rect.left -= 50;
    chest_rect.top -= 50;
    chest_rect.width += 100;
    chest_rect.height += 300;
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->obj == NULL) {
        return;
    }
    player_rect = sfSprite_getGlobalBounds(player->obj->drawable.sprite);
    if (sfFloatRect_intersects(&player_rect, &chest_rect, NULL) == sfTrue &&
            dico_t_get_value(obj->components, scd_rect_key) != NULL) {
        check_have_enough_infinity_86(player, obj, win, scene);
    } else if (dico_t_get_value(obj->components, scd_rect_key) == NULL) {
        chest_rect = sfSprite_getGlobalBounds(obj->drawable.sprite);
        if (sfFloatRect_intersects(&chest_rect, &player_rect, NULL) == sfTrue) {
            add_text_dialog_json(win, check_into_chest_json, &reaload_dialogs, obj);
            obj->update = NULL;
        }
    }
}

void init_chest(object_t *obj, scene_t *scene, window_t *win,
    float dtime)
{
    any_t *json = NULL;
    any_t *sprite_path = NULL;
    object_t *npc = NULL;
    int *rect = NULL;
    int *scd_rect_array = NULL;
    sfIntRect *scd_rect = malloc(sizeof(sfIntRect));

    if (obj == NULL || obj->components == NULL ||
            scene == NULL || win == NULL || scd_rect == NULL) {
        return;
    }
    json = parse_json_file(dico_t_get_value(obj->components, npc_path_key));
    rect = get_any_int_array(get_from_any(json, "d", rect_key));
    scd_rect_array = get_any_int_array(get_from_any(json, "d", scd_rect_key));
    sprite_path = get_from_any(json, "d", sprite_path_key);
    if (rect == NULL || sprite_path == NULL || sprite_path->type != STR ||
            scd_rect_array == NULL) {
        return;
    }
    npc = create_object(update_chest, NULL, scene, LAYER_ENNEMY);
    if (object_set_sprite(npc, sprite_path->value.str, (sfIntRect)
            {rect[0], rect[1], rect[2], rect[3]},
            obj->bigdata.sprite_bigdata.pos) != RET_OK) {
        return;
    }
    obj->components = dico_t_rem(obj->components, npc_path_key);
    *scd_rect = (sfIntRect) {scd_rect_array[0], scd_rect_array[1],
        scd_rect_array[2], scd_rect_array[3]};
    npc->components = dico_t_add_data(npc->components, scd_rect_key, scd_rect,
        free);
}
