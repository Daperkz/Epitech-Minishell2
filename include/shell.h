/*
** EPITECH PROJECT, 2026
** minishell.h
** File description:
** minishell
*/

#ifndef SHELL_H_
    #define SHELL_H_

    #include <unistd.h>
    #include <sys/wait.h>

    #include "shell/macro.h"
    #include "shell/builtins.h"
    #include "shell/utils.h"

typedef struct minishell_s {
    int last_errno;
    char **env;
    char *cwd; // current working directory
    char *owd; // old working directory
    char *hwd; // home working directory
    char **path_arr;
    pid_t pid;
    char *input;
    ssize_t input_len;
    char **commands;
    int nbr_commands;
    char **input_array;
    int input_array_len;
    int pipe_fds[2];
    pid_t child;
    int child_status;
} shell_t;

int init_shell(shell_t *shell, char **env);

int exit_mysh(ssize_t nread);

int parse_input(shell_t *shell);
int single_command(shell_t *shell, char *command, int is_piped);
int handle_redirections(shell_t *shell);
int builtins(shell_t *shell);
int pipe_handler(shell_t *shell, char *command);
char *find_command(shell_t *shell);
int process_input(shell_t *shell);
int single_command(shell_t *shell, char *command, int is_piped);

int execute_child(shell_t *shell, char *program_path);
int execute_command(shell_t *shell, char *program_path);

void print_the_prompt(shell_t *shell);

void destroy_shell(shell_t *shell);

#endif /* !SHELL_H_ */
