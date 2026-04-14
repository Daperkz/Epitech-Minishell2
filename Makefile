##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## Makefile
##

NAME	=	mysh
CC	=	epiclang

ROOT_DIR	=	./
LIB_DIR	=	$(ROOT_DIR)third_party/my/

INCLUDE	=	$(ROOT_DIR)include/
LIB_INCLUDE	=	$(LIB_DIR)include/

CFLAGS	=	-I$(INCLUDE) -I$(LIB_INCLUDE) -g3 -Wall -Wextra
LDFLAGS	=	-L$(LIB_DIR) -lmy

OBJ_D	=	$(ROOT_DIR)obj/
SRC_D	=	$(ROOT_DIR)src/

SHELL_D	=	$(SRC_D)shell/
FEATURES_D	=	$(SRC_D)features/
BUILTINS_D	=	$(FEATURES_D)builtins/
INPUTS_D	=	$(SRC_D)inputs/
REDIRECTION_D	=	$(INPUTS_D)redirection/
PIPE_D	=	$(INPUTS_D)pipe/
UTILS_D	=	$(SRC_D)utils/
STRINGS_D	=	$(UTILS_D)strings/
AST_D	=	$(SRC_D)ast/
AST_DATA_D	=	$(AST_D)data/
AST_RULES_D	=	$(AST_D)rules/

SHELL_F	=	init_shell.c	\
			the_prompt.c	\
			destroy_shell.c

FEATURES_F	=	builtins_handler.c


BUILTINS_F	=	exit.c	\
				cd.c	\
				env.c	\
				setenv.c	\
				unsetenv.c

INPUTS_F	=	parser.c	\
				process_input.c	\
				single_command.c	\
				executor.c	\
				pipe_handler.c	\
				redirections_handler.c

REDIRECTION_F	=	error.c	\
					heredoc.c	\
					redirect.c	\
					utils.c

PIPE_F	=	child.c	\
			executor.c	\
			builtin.c

UTILS_F	=	signal_handling.c	\
			get_env_var.c	\
			get_path_array.c	\
			refresh_path.c

STRINGS_F	=	find_command.c	\
				join_path.c	\
				my_str_is_alphanumeric.c	\
				tilde_expansion.c	\
				my_strstr_unquoted.c

AST_F	=	create.c	\
			execute.c

AST_DATA_F	=	create.c	\
				destroy.c

AST_RULES_F	=	command_seperator.c	\
				pipe.c	\
				dlsr.c	\
				lsr.c	\
				dgrt.c	\
				grt.c	\
				command.c

SRC	=	$(addprefix $(SRC_D), minishell.c)	\
		$(addprefix $(SHELL_D), $(SHELL_F))	\
		$(addprefix $(FEATURES_D), $(FEATURES_F))	\
		$(addprefix $(INPUTS_D), $(INPUTS_F))	\
		$(addprefix $(BUILTINS_D), $(BUILTINS_F))	\
		$(addprefix $(REDIRECTION_D), $(REDIRECTION_F))	\
		$(addprefix $(PIPE_D), $(PIPE_F))	\
		$(addprefix $(UTILS_D), $(UTILS_F))	\
		$(addprefix $(STRINGS_D), $(STRINGS_F))	\
		$(addprefix $(AST_D), $(AST_F))	\
		$(addprefix $(AST_DATA_D), $(AST_DATA_F))	\
		$(addprefix $(AST_RULES_D), $(AST_RULES_F))	\


OBJ	=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(MAKE) -j$$(nproc) -C $(LIB_DIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(OBJ_D)%.o:	$(SRC_D)%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	rm -rf $(OBJ_D)

fclean:
	@$(MAKE) fclean -C $(LIB_DIR)
	rm -rf $(OBJ_D)
	rm -f $(NAME)

re:	fclean	$(NAME)

.PHONY:	all	clean	fclean	re
