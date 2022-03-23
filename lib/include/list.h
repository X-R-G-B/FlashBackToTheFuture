/*
** EPITECH PROJECT, 2021
** inlude list
** File description:
** chained list header
*/

#ifndef LIST_H_
    #define LIST_H_

typedef struct list list_t;
typedef struct list_ptr list_ptr_t;

struct list_ptr
{
    int len;
    list_t *start;
    list_t *end;
};
struct list
{
    void *var;
    list_t *back;
    list_t *next;
};

list_ptr_t *list_create(void);
void *list_add_to_end(list_ptr_t *list_ptr, void *content);
void *list_add_to_start(list_ptr_t *list_ptr, void *content);
void *list_add_to_i(list_ptr_t *list_ptr, void *content, int i);
void swap_two_elem(list_ptr_t *list_ptr, int x, int y);
void move_first_elem_to_end(list_ptr_t *list_ptr);
void move_last_elem_to_start(list_ptr_t *list_ptr);
void rev_list(list_ptr_t *list_ptr);
void *get_element_i_var(list_ptr_t *list_ptr, int x);
list_t *get_element_i(list_ptr_t *list_ptr, int x);
void free_list(list_ptr_t *list_ptr);
void rm_fst_elem(list_ptr_t *list_ptr);
void rm_last_elem(list_ptr_t *list_ptr);
void rm_elem_i(list_ptr_t *list_ptr, int x);
char *str_from_list(list_t *elem);
list_ptr_t *str_to_word_list(char *str);

#endif /* !LIST_H_ */
