/*
** EPITECH PROJECT, 2025
** my_word_array_len.c
** File description:
** calculates the number of words the array has
*/

long my_word_array_len(char **word_array)
{
    long len = 0;

    while (word_array && *word_array) {
        len++;
        word_array++;
    }
    return len;
}
