/*
** EPITECH PROJECT, 2025
** my_str_isalpha
** File description:
** returns 1 if the string passed as parameter only contains alphabetical
** characters and 0 if the string contains another type of character.
*/

int my_str_isalpha(char const *str)
{
    while (*str) {
        if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))) {
            return 0;
        }
        str++;
    }
    return 1;
}
