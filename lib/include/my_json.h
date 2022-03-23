/*
** EPITECH PROJECT, 2022
** libjson
** File description:
** lib json header
*/

#ifndef LIBJSON_H_
    #define LIBJSON_H_

    #include <stdarg.h>
    #include "list.h"
    #include "my_dico.h"

    #define JS_OK 0
    #define JS_ERR_PATH 1
    #define JS_ERR_MALLOC 2
    #define JS_ERR_INPUT 3

enum any_type_e {
    CHAR,
    STR,
    INT,
    FLOAT,
    ARRAY,
    DICT
};
typedef enum any_type_e any_type_t;

struct any_s {
    any_type_t type;
    union value_s {
        char *str;
        int i;
        float f;
        list_ptr_t *array;
        dico_t *dict;
        char c;
    } value;
};
typedef struct any_s any_t;

struct json_s {
    any_t *dico;
    int nb_keys;
};
typedef struct json_s json_t;

// ----------------------------------------------------------------------------

any_t *any_dup(any_t *any);

any_t *parse_json_file(char const path[]);

any_t *parse_json_str(char const *str);

char *rm_space(char const *str);

dico_t *parse_json(char *file);

int prety_print(any_t *any, int fd);

any_t *get_from_any(any_t *any, char const *format, ...);

any_t *dico_t_get_any(dico_t *dico, char const *key);

any_t *create_any(char c);

int pop_data(list_ptr_t *pile, any_t *any);

char *rm_space(char const *str);

int write_json(any_t *any, char const *path);

void destroy_any(void *data);

void destroy_pile(list_ptr_t *pile);

void fill_data(char origin, char *end, any_t *any);

char **get_any_string_array(any_t *array);

int *get_any_int_array(any_t *array);

float *get_any_float_array(any_t *array);

#endif
