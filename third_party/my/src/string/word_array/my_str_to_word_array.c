/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** splits a string into words.
** Separators will all be non-alphanumeric characters.
** The function returns an array in which each cell contains the address of a
** string (representing a word).
** The last cell is null to terminate the array
*/

#include <stdlib.h>

#include "my/string.h"

static int is_seperator(char c, char const *seps)
{
    for (int i = 0; seps[i]; i++) {
        if (c == seps[i])
            return 1;
    }
    return 0;
}

static int nbr_words(char const *str, char const *seps)
{
    int in_word = 0;
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (!is_seperator(str[i], seps) && !in_word) {
            in_word = 1;
            count++;
            continue;
        }
        if (is_seperator(str[i], seps)) {
            in_word = 0;
        }
    }
    return count;
}

static char *extract_word(char const *str, char const *seps, int *i_ptr)
{
    int start = *i_ptr;
    int len;

    while (str[*i_ptr] && !is_seperator(str[*i_ptr], seps))
        (*i_ptr)++;
    len = *i_ptr - start;
    return my_strndup(&str[start], len);
}

static int skip_seps(char const *str, char const *seps, int *i_ptr)
{
    while (str[*i_ptr] && is_seperator(str[*i_ptr], seps))
        (*i_ptr)++;
    return (*i_ptr);
}

char **my_str_to_word_array(char const *str, char const *seps)
{
    char **word_array = NULL;
    int wi = 0;

    if (!str || !seps)
        return NULL;
    word_array = malloc(sizeof(char *) * (nbr_words(str, seps) + 1));
    if (!word_array)
        return NULL;
    for (int i = 0; str[i]; wi++) {
        if (!str[skip_seps(str, seps, &i)])
            break;
        word_array[wi] = extract_word(str, seps, &i);
        if (!word_array[wi]) {
            my_free_word_array(word_array);
            return NULL;
        }
    }
    word_array[wi] = NULL;
    return word_array;
}
