##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## Makefile
##

NAME			=	mysh
CC				=	epiclang

ROOT_D			=	./
LIB_D			=	$(ROOT_D)third_party/my/
INCLUDE			=	$(ROOT_D)include/
LIB_INCLUDE		=	$(LIB_D)include/
OBJ_D			=	$(ROOT_D)obj/
SRC_D			=	$(ROOT_D)src/

SHELL_D			=	$(SRC_D)shell/
FEATURES_D		=	$(SRC_D)features/
BUILTINS_D		=	$(FEATURES_D)builtins/
REDIRECTION_D	=	$(FEATURES_D)redirections/
UTILS_D			=	$(SRC_D)utils/
STRINGS_D		=	$(UTILS_D)strings/
AST_D			=	$(SRC_D)ast/
AST_DATA_D		=	$(AST_D)data/
AST_RULES_D		=	$(AST_D)rules/

CPPFLAGS		=	-I$(INCLUDE) -I$(LIB_INCLUDE)
CFLAGS			=	-Wall -Wextra -MMD
CFLAGS_DEBUG	=	-g3
CFLAGS_TEST		=	--coverage
LDFLAGS			=	-L$(LIB_D) -lmy

SHELL_F			=	init_shell.c	\
					the_prompt.c	\
					destroy_shell.c

FEATURES_F		=	builtins_handler.c	\
					command.c	\
					child.c	\
					pipe.c


BUILTINS_F		=	exit.c	\
					cd.c	\
					env.c	\
					setenv.c	\
					unsetenv.c


REDIRECTION_F	=	error.c	\
					dgrt.c	\
					dlsr.c	\
					grt.c	\
					lsr.c


UTILS_F			=	is_myshtty.c	\
					signal_handling.c	\
					get_env_var.c	\
					get_path_array.c	\
					refresh_path.c

STRINGS_F		=	find_command.c	\
					join_path.c	\
					my_str_is_alphanumeric.c	\
					tilde_expansion.c	\
					my_strstr_unquoted.c

AST_F			=	create.c	\
					execute.c	\
					pipeline.c

AST_DATA_F		=	create.c	\
					destroy.c

AST_RULES_F		=	command_seperator.c	\
					pipe.c	\
					dlsr.c	\
					lsr.c	\
					dgrt.c	\
					grt.c	\
					command.c

SRC				=	$(addprefix $(SRC_D), minishell.c)	\
					$(addprefix $(SHELL_D), $(SHELL_F))	\
					$(addprefix $(FEATURES_D), $(FEATURES_F))	\
					$(addprefix $(INPUTS_D), $(INPUTS_F))	\
					$(addprefix $(BUILTINS_D), $(BUILTINS_F))	\
					$(addprefix $(REDIRECTION_D), $(REDIRECTION_F))	\
					$(addprefix $(UTILS_D), $(UTILS_F))	\
					$(addprefix $(STRINGS_D), $(STRINGS_F))	\
					$(addprefix $(AST_D), $(AST_F))	\
					$(addprefix $(AST_DATA_D), $(AST_DATA_F))	\
					$(addprefix $(AST_RULES_D), $(AST_RULES_F))	\


OBJ				=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

DEPENDENCY		=	$(OBJ:%.o=%.d)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(MAKE) -j$$(nproc) -C $(LIB_D)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_D)%.o:	$(SRC_D)%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

debug:	CFLAGS += $(CFLAGS_DEBUG)
debug:	re

tests:	CFLAGS += $(CFLAGS_TEST)
tests:	re

clean:
	@$(MAKE) clean -C $(LIB_D)
	rm -rf $(OBJ_D)

fclean:
	@$(MAKE) fclean -C $(LIB_D)
	rm -rf $(OBJ_D)
	rm -f $(NAME)

re:	fclean	$(NAME)

.PHONY:	all	debug	tests	clean	fclean	re
-include $(DEPENDENCY)