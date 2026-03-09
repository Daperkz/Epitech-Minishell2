/*
** EPITECH PROJECT, 2025
** file_utils.h
** File description:
** file_utils
*/

#ifndef MY_FILE_H_
    #define MY_FILE_H_

int open_file(const char *filename);

long get_file_size(const char *filename);
long get_file_size_dyn(const char *filename);

char *get_file_content(int fd, long size);

char *read_file(const char *filename);
char *read_file_dyn(const char *filename);

#endif /* !FILE_UTILS_H_ */
