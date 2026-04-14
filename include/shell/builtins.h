/*
** EPITECH PROJECT, 2026
** builtins.h
** File description:
** builtins
*/

#ifndef BUILTINS_H_
    #define BUILTINS_H_

    #define EXIT_INPUT "exit"
    #define CD_INPUT "cd"
    #define ENV_INPUT "env"
    #define SETENV_INPUT "setenv"
    #define UNSETENV_INPUT "unsetenv"

typedef struct minishell_s shell_t;

typedef struct builtin_s {
    char *name;
    int (*func)(shell_t *, char **);
} builtin_t;

int exit_builtin(shell_t *shell, char **cmd_args);
int cd_builtin(shell_t *shell, char **cmd_args);
int env_builtin(shell_t *shell, char **cmd_args);
int setenv_builtin(shell_t *shell, char **cmd_args);
int unsetenv_builtin(shell_t *shell, char **cmd_args);

extern const builtin_t BUILTINS[];

#endif /* !BUILTINS_H_ */
