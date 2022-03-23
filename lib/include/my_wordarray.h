/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** manage char ** word array
*/

#ifndef WORD_ARRAY_H_
    #define WORD_ARRAY_H_

/**
** @brief free a word array null terminated
** @param arr
**/
void my_wordarray_free(char **arr);

/**
** @brief put each "word" defining by delimiters in a 2d array
** @param str
** @param delim
** @return null if any error occurs; else the 2d array
**/
char **my_wordarray_from_str(const char *str, char delim);

/**
** @brief copy a null terminated 2d array null terminated 1d array
** @param env[]
** @return null if lenght of env is 0 or cant malloc; else the new 2d array
**/
char **my_wordarray_from_wordarray(char *const env[]);

/**
** @brief search the first occurence of str in the 2d array and get its index
** @param arr
** @param str
** @return -1 if arr is null or there is no occurence; otherwise the index
**/
int my_wordarray_get_index_startswith(char *const *arr, char const *str);

/**
** @brief get length of null terminated 2d array
** @param array
** @return 0 if array is null; else the length
**/
int my_wordarray_len(char *const *array);

/**
** @brief print each char * of the 2d array with a newline after each char *
** @param array
**/
void my_wordarray_showln(char *const *array);

/**
** @brief print each char * of the 2d array
** @param array
**/
void my_wordarray_show(char *const *array);

void my_wordarray_write(char *const *array, char const *path);

#endif
