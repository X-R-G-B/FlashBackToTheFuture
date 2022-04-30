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

/**
** @brief parse a json file to any_t
**
** @param path path to the json file
**
** @return {
** NULL : path is NULL,
** NULL : path is bad,
** NULL : malloc failed,
** any_t *: the file has been parsed
** }
**/
any_t *parse_json_file(char const path[]);

/**
** @brief parse a char * to any_t
**
** @param str char * to parse
**
** @return {
** NULL : str is NULL,
** NULL : malloc failed,
** any_t *: the char * has been parsed
** }
**/
any_t *parse_json_str(char const *str);

char *rm_space(char const *str);

//dico_t *parse_json(char *file);

/**
** @brief print any_t to the file descriptor
**
** @param any the any_t to print
** @param fd filedescriptor to use
**
** @return {
** int : number of char writed
** }
**/
int prety_print(any_t *any, int fd);

/**
** @brief get unlimited nested data
**
** to get value of a dico : "d", "key"
** to get specific index array : "a", 2
** you can mix the two
** (any, "da", "key", 2)
**
** @param any any in wich the values are
** @param format format to use
** @param ... unlimited arguments
**
** @return {
** NULL : any or format is NULL,
** NULL : the value don't exists,
** any_t *: the value asked
** }
**/
any_t *get_from_any(any_t *any, char const *format, ...);

/**
** @brief get any_t from a dico_t (cast void * of dico_t value)
**
** @param dico dico in which the key are
** @param key key to represent the value
**
** @return {
** NULL : dico or key is NULL,
** NULL : the key don't exists
** any_t *: the value asked
** }
**/
any_t *dico_t_get_any(dico_t *dico, char const *key);

any_t *create_any(char c);

int pop_data(list_ptr_t *pile, any_t *any);

char *rm_space(char const *str);

/**
** @brief write any_t to a json file
**
** @param any any to write
** @param path path to a file that will be override
**
** @return {
** int : nb of char writed
** }
**/
int write_json(any_t *any, char const *path);

/**
** @brief destroy any
**
** @param data any_t to destroy
**/
void destroy_any(void *data);

void destroy_pile(list_ptr_t *pile);

void fill_data(char origin, char *end, any_t *any);

/**
** @brief parse any_t to a char **
**
** @param array any_t in which the array of char * is
**
** @return {
** NULL : array is NULL,
** NULL : array contains other than char *,
** char **: the values asked
** }
**/
char **get_any_string_array(any_t *array);

/**
** @brief parse any_t to a int *
**
** @param array any_t in which the array int is
**
** @return {
** NULL : array is NULL,
** NULL : array contains other than int
** int *: the values asked
** }
**/
int *get_any_int_array(any_t *array);

/**
** @brief parse any_t to a float *
**
** @param array any_t in which the array float is
**
** @return {
** NULL : array is NULL,
** NULL : array contains other than float,
** float *: the values asked
** }
**/
float *get_any_float_array(any_t *array);

#endif
