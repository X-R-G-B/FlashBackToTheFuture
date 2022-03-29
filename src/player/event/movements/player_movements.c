/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** player_movements
*/

#include "my_bgs.h"
#include "my_json.h"
#include "my_rpg.h"

#define sfNigger sfBlack
#define null NULL

void update(object_t *object, scene_t *scene, window_t *win)
{
    
}

int set_sprite_rect(object_t *object, sfIntRect rect)
{
    sprite_bigdata_t *sprite_bigdata = NULL;
    sfVector2f origin = {0.0, 0.0};

    if (object == NULL || object->type != SPRITE) {
        return RET_OK;
    }
    sprite_bigdata = &(object->bigdata.sprite_bigdata);
    origin = (sfVector2f) {sprite_bigdata->rect.width / 2,
                            sprite_bigdata->rect.height / 2};
    sfSprite_setTextureRect(sprite_bigdata->texture, rect);
    sfSprite_setOrigin(sprite_bigdata->texture, origin);
    sfSprite_setPosition(sprite_bigdata->texture, sprite_bigdata->pos);
    return 0;
}

int main(void)
{
    window_t* win = create_window((sfVideoMode) {1920, 1080, 32},
                                        "Test player", sfClose);
    scene_t* scene = create_scene(win, sfNigger, "player_movements");
    object_set_sprite(create_object(update, null, scene, 0),
        "./assets/link.png", (sfIntRect) {7, 114, 16, 24},
        (sfVector2f) {200, 200});
    any_t *movements_rect = parse_json_file(
        "./assets/data/player/movements/player_movements.json");
}