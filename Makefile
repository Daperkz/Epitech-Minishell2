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
INPUTS_D	=	$(SRC_D)inputs/
BUILTINS_D	=	$(INPUTS_D)builtins/
UTILS_D	=	$(SRC_D)utils/
STRINGS_D	=	$(UTILS_D)strings/
SHELL_F	=	init_shell.c	\
			the_prompt.c	\
			destroy_shell.c

INPUTS_F	=	process_input.c	\
				parser.c	\
				executor.c	\
				builtins_handler.c	\
				pipe_handler.c

BUILTINS_F	=	exit.c	\
				cd.c	\
				env.c	\
				setenv.c	\
				unsetenv.c

UTILS_F	=	signal_handling.c	\
			get_env_var.c	\
			get_path_array.c	\
			refresh_path.c

STRINGS_F	=	find_command.c	\
				join_path.c	\
				my_str_is_alphanumeric.c	\
				tilde_expansion.c

SRC	=	$(addprefix $(SRC_D), minishell.c)	\
		$(addprefix $(SHELL_D), $(SHELL_F))	\
		$(addprefix $(INPUTS_D), $(INPUTS_F))	\
		$(addprefix $(BUILTINS_D), $(BUILTINS_F))	\
		$(addprefix $(UTILS_D), $(UTILS_F))	\
		$(addprefix $(STRINGS_D), $(STRINGS_F))	\


OBJ	=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -j$$(nproc) -C $(LIB_DIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(OBJ_D):
	mkdir -p $@

$(OBJ_D)%.o:	$(SRC_D)%.c	|	$(OBJ_D)
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	make clean -C $(LIB_DIR)
	rm -rf $(OBJ_D)

fclean:
	make fclean -C $(LIB_DIR)
	rm -rf $(OBJ_D)
	rm -f $(NAME)

re:	fclean	$(NAME)

.PHONY:	all	clean	fclean	re
