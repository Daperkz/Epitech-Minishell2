/*
** EPITECH PROJECT, 2025
** my_strcapitalize
** File description:
** capitalizes the first letter of each word
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
        if ((i == 0 || (str[i - 1] >= 32 && str[i - 1] <= 47)
                || (str[i - 1] >= 58 && str[i - 1] <= 64)
                || (str[i - 1] >= 91 && str[i - 1] <= 96)
                || (str[i - 1] >= 123 && str[i - 1] <= 126))
            && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] += ('A' - 'a');
        i++;
    }
    return str;
}
