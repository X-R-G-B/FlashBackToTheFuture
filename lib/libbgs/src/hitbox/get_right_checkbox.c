/*
** EPITECH PROJECT, 2022
** defender
** File description:
** get right
*/

#include "my_bgs.h"
#include "my_bgs_components.h"

sfFloatRect get_right_checkbox(object_t *obj, sfFloatRect *rect)
{
    const sfImage *img = NULL;
    sfVector2u size = {0};
    sfFloatRect bounces = {0};
    sfFloatRect new = {0};

    if (obj == NULL || rect == NULL) {
        return ((sfFloatRect) {-1, -1, -1, -1});
    }
    bounces = sfSprite_getGlobalBounds(obj->drawable.sprite);
    img = obj->bigdata.sprite_bigdata.image;
    size = sfImage_getSize(img);
    new.width = (bounces.width * rect->width) / size.x;
    new.height = (bounces.height * rect->height) / size.y;
    new.left = bounces.left + ((bounces.width * rect->left) / size.x);
    new.top = bounces.top + ((bounces.height * rect->top) / size.y);
    return (new);
}
