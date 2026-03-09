/*
** EPITECH PROJECT, 2025
** switch_base_flag
** File description:
** switch for all base flags
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include "all_parameters.h"
#include "count_error.h"

#include "my/string.h"
#include "my/utils.h"
/*
static int my_strisstr(const char *format, char *modifier)
{
    for (int j = 0; modifier[j] != 0; j++) {
        if (modifier[j] != format[j]) {
            return 0;
        }
    }
    return 1;
}

int *parse_all_flag(const char *format)
{
    int *mod = malloc(sizeof(int) * 1);
    char *all_modifier[15] = {
        "-", "-*", "+", " ", "0", "#", ".", ".*", "*",
        "hh", "h", "l", "ll", "L", "t",
        0
    };

    mod[0] = 0;
    for (int i = 0; all_modifier[i] != 0; i++) {
        if (my_stristr(format, all_modifier[i])) {
            my_strcat(mod, i);
            format += my_strlen(all_modifier[i] - 1);
        }
    }
    my_strcat(mod, 14);
    return mod;
}
*/

int format_gestion(int fd, va_list args, const char *format, cot_err_t *coterr)
{
    int written;
    char *str = NULL;

    for (int i = 0; ALL_FORMAT[i]->flag != 0; i++) {
        if (*format == ALL_FORMAT[i]->flag) {
            str = ALL_FORMAT[i]->func(args, coterr);
            written = my_putstr_fd(fd, str);
            coterr->error = (written == -1) ? 1 : coterr->error;
            coterr->count += (written == -1) ? 0 : written;
            free(str);
            return 1;
        }
    }
    return 0;
}

int sformat_gestion(
    char **str_ptr, va_list args, char *format, cot_err_t *coterr
)
{
    char *str = NULL;

    for (int i = 0; ALL_FORMAT[i]->flag != '\0'; i++) {
        if (*format == ALL_FORMAT[i]->flag) {
            str = ALL_FORMAT[i]->func(args, coterr);
            my_strappend(str_ptr, str);
            coterr->count += my_strlen(str);
            free(str);
            return 1;
        }
    }
    return 0;
}
