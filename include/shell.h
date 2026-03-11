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

    #include "shell/builtins.h"
    #include "shell/utils.h"

    #define MALLOC_FAIL (void *)-1

    #define EXIT_SUCCESS 0
    #define EXIT_FAILURE 1
    #define EXIT_ERROR 84
    #define EXIT_ACTION_DONE 2
    #define EXIT_SHUTDOWN 3

    #define ENV_VAR_PWD "PWD="
    #define ENV_VAR_PWD_SIZE 4
    #define ENV_VAR_OLDPWD "OLDPWD="
    #define ENV_VAR_OLDPWD_SIZE 7
    #define ENV_VAR_PATH "PATH="
    #define ENV_VAR_PATH_SIZE 5
    #define ENV_VAR_ZDOTDIR "ZDOTDIR="
    #define ENV_VAR_ZDOTDIR_SIZE 8

    #define ZSH_RED "\033[38;5;160m"
    #define COLOR_RESET "\033[0m"

    #define THE_PROMPT "$ "
    #define THE_PROMPT_SIZE 2

    #define COMMAND_SEPERATOR ";"

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
    pid_t child;
    int child_status;
} shell_t;

int init_shell(shell_t *shell, char **env);

int exit_mysh(ssize_t nread);

int parse_input(shell_t *shell);
int builtins(shell_t *shell);

char *find_command(shell_t *shell);
int execute_command(shell_t *shell, char *program_path);

int process_input(shell_t *shell);

void print_the_prompt(shell_t *shell);

void destroy_shell(shell_t *shell);

#endif /* !SHELL_H_ */
