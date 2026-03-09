/*
** EPITECH PROJECT, 2025
** my_strlowcase
** File description:
** puts every uppercase letters to a lowercase
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ('a' - 'A');
        i++;
    }
    return str;
}
