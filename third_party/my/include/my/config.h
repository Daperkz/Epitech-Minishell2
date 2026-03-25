/*
** EPITECH PROJECT, 2026
** config.h
** File description:
** config
*/

#ifndef CONFIG_H_
    #define CONFIG_H_

    #include "hashtable.h"
    #include "utils.h"
    #include "string.h"

    #define CONFIG_DEFAULT_SIZE 50

    #define CONFIG_GET(conf, key) ht_get(conf, key)
    #define CONFIG_GET_INT(conf, key) my_atoi(ht_get(conf, key))
    #define CONFIG_GET_FLOAT(conf, key) my_atof(ht_get(conf, key))

    #define CONFIG_DUMP(conf) ht_dump(conf, my_putstr)

    #define CONFIG_DESTROY(conf) ht_destroy(conf, free)

typedef ht_t config_t;

/*
** reads a file to output a hashtable of all the values found
** chore: strip the key and values when found
*/
config_t *config_create(char const *filepath, int size);


#endif /* !CONFIG_H_ */
