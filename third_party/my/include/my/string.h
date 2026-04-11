/*
** EPITECH PROJECT, 2025
** string_utils.h
** File description:
** string_utils
*/

#ifndef MY_STRING_H_
    #define MY_STRING_H_

    #define WHITESPACES " \t\r\n"


/* --- string array --- */

char **my_str_to_str_arr(char const *str, char const *seps);
long my_len_str_arr(char **str_arr);
void my_put_str_arr(char **str_arr, char sep);
char **my_cpy_str_arr(char **str_arr);
void my_free_str_arr(char **str_arr);

/* --- convert --- */

int my_atoi(char const *str);
double my_atof(char *str);
double my_getfnbrspe(char *str, int *error_ptr);
int my_getnbrspe(char *str, int *error_ptr);


/* --- manipulation --- */

int my_strlen(char const *str);
int my_strlen_d(char const *str, char delim);
int my_putstr(char const *str);
int my_fputstr(int fd, char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
char *my_revstr(char *str);
char *my_strappend(char **dest_ptr, char *src);
char *my_strtrim(char *str, char *seps);

char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);

/* --- search --- */

char *my_strstr(char *str, char const *to_find);
char *my_strchr(char *str, char target);
char *my_strrchr(char *str, char target);
char *my_strsep(char **str_ptr, const char *sep);

/* --- comparaison --- */

int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);

#endif /* !STRING_UTILS_H_ */
