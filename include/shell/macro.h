/*
** EPITECH PROJECT, 2026
** macro.h
** File description:
** macro
*/

#ifndef SHELL_MACRO_H_
    #define SHELL_MACRO_H_

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

    #define ZSH_NOERR_COLOR "\033[38;5;82m"
    #define ZSH_ERR_COLOR "\033[38;5;160m"
    #define ZSH_CWD_COLOR "\033[1;36m"
    #define COLOR_RESET "\033[0m"

    #define THE_PROMPT "$ "
    #define THE_PROMPT_SIZE 2

    #define COMMAND_SEPERATOR ";"
    #define PIPE_SEPERATOR "|"

    #define GRT ">" //redirection out type
    #define DGRT ">>" //redirection out append type
    #define LSR "<" //redirection in type
    #define DLSR "<<" //redirection heredoc type
    #define REDIR_MSSING_NAME_ERR "Missing name for redirect.\n"
    #define REDIR_AMBIGUOUS_OUT_ERR "Ambiguous output redirect.\n"
    #define REDIR_AMBIGUOUS_IN_ERR "Ambiguous input redirect.\n"
    #define REDIR_HEREDOC_TMP_FILE "/tmp/.heredoc_tmp"
    #define REDIR_HEREDOC_MESSAGE "? "
    #define REDIR_HEREDOC_MESSAGE_LEN 2

    #define INVALID_COMMAND "Invalid null command.\n"

#endif /* !SHELL_MACRO_H_ */
