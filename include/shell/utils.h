/*
** EPITECH PROJECT, 2026
** utils.h
** File description:
** utils
*/

#ifndef SHELL_UTILS_H_
    #define SHELL_UTILS_H_

    #define BASIC_SEPERATOR " \t\n"

typedef struct minishell_s shell_t;

// function for the CTRL + C signal to not crash terminal
void handle_sigint(int sig);

//takes care of errno values message printing from status of child
void handle_child_status(shell_t *shell, int status);

char *join_path(char *path, char *command);

char *get_env_var(char **env, char *var, int size);
char **get_path_array(char **env);
int refresh_path(shell_t *shell);

int my_isletter(char c);
int my_str_is_alphanumeric(char *str);

int tilde_expansion(shell_t *shell);

#endif /* !UTILS_H_ */
