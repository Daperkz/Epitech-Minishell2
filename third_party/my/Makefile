##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## lib makefile
##

NAME	=	libmy.a
CC	=	epiclang

ROOT_DIR	=	./

# -_- Public include for my = ./include -_-
INCLUDE	=	$(ROOT_DIR)include/
# -_- Internal / Private include for my_printf = ./src/printf/private -_-
MY_PRINTF_INCLUDE	=	$(ROOT_DIR)src/printf/private

override CFLAGS	+=	-I$(INCLUDE) -I$(MY_PRINTF_INCLUDE) -g3 -Wall -Wextra -MMD -MP

OBJ_D	=	$(ROOT_DIR)obj/

SRC_D	=	$(ROOT_DIR)src/

# -_- Directories located in $(SRC_D) = ./src/ -_-
IO_D	=	$(SRC_D)io/
STRING_D	=	$(SRC_D)string/
MATH_D	=	$(SRC_D)math/
UTILS_D	=	$(SRC_D)utils/
FILE_D	=	$(SRC_D)file/
MY_PRINTF_D	=	$(SRC_D)printf/
LINKED_LISTS_D	=	$(SRC_D)linked_lists/
HASHTABLE_D	=	$(SRC_D)hashtable/

# -_- Directories located in $(STRING_D) = ./src/string/ -_-
COMPARAISON_D	=	$(STRING_D)comparaison/
CONVERT_D	=	$(STRING_D)convert/
MANIPULATION_D	=	$(STRING_D)manipulation/
SEARCH_D	=	$(STRING_D)search/
WORD_ARRAY_D	=	$(STRING_D)word_array/

# -_- Directories located in $(MY_PRINTF_D) = ./src/printf/ -_-
MY_PRINTF_UTILS_D	=	$(MY_PRINTF_D)utils/
MY_PRINTF_PARAM_D	=	$(MY_PRINTF_D)parameters/
MY_PRINTF_MODIFIER_D	=	$(MY_PRINTF_D)modifiers/

# -_- Directories located in $(LINKED_LISTS_D) = ./src/linked_lists/ -_-
NODE_LL_D	=	$(LINKED_LISTS_D)node/
SIMPLE_LL_D	=	$(LINKED_LISTS_D)simple/
DOUBLE_LL_D	=	$(LINKED_LISTS_D)double/


# -_- Files located in $(IO_D) = ./src/io/ -_-
IO_F	=	my_putchar.c	\
			my_put_nbr.c	\
			my_put_float.c	\
			my_showstr.c	\
			my_showmem.c	\
			my_show_word_array.c

# -_- Files located in $(STRING_D) = ./src/string/ -_-
STRING_F	=	

# -_- Files located in $(COMPARAISON_D) = ./src/string/comparaison/ -_-
COMPARAISON_F	=	my_str_isalpha.c	\
					my_str_islower.c	\
					my_str_isnum.c	\
					my_str_isprintable.c	\
					my_str_isupper.c	\
					my_strcmp.c	\

# -_- Files located in $(CONVERT_D) = ./src/string/convert/ -_-
CONVERT_F	=	my_atoi.c	\
				my_atof.c

# -_- Files located in $(COMPARAISON_D) = ./src/string/comparaison/ -_-
MANIPULATION_F	=	my_putstr.c	\
					my_revstr.c	\
					my_strappend.c	\
					my_strcapitalize.c	\
					my_strcat.c	\
					my_strcpy.c	\
					my_strdup.c	\
					my_strlen.c	\
					my_strlowcase.c	\
					my_strupcase.c

# -_- Files located in $(SEARCH_D) = ./src/string/search/ -_-
SEARCH_F	=	my_strchr.c	\
				my_strrchr.c	\
				my_strsep.c	\
				my_strstr.c

# -_- Files located in $(WORD_ARRAY_D) = ./src/string/word_array/ -_-
WORD_ARRAY_F	=	my_str_to_word_array.c	\
					my_print_word_array.c	\
					my_word_array_len.c	\
					my_copy_word_array.c	\
					my_free_word_array.c

# -_- Files located in $(MATH_D) = ./src/math/ -_-
MATH_F	=	my_isneg.c	\
			my_compute_power_rec.c	\
			my_compute_square_root.c	\
			my_is_prime.c	\
			my_find_prime_sup.c	\
			my_ipow.c	\
			my_factorial.c	\
			my_rounds.c	\
			my_nbrlen.c	\
			my_sign.c

# -_- Files located in $(UTILS_D) = ./src/utils/ -_-
UTILS_F	=	my_swap.c	\
			my_sort_int_array.c	\
			concat_params.c	\
			convert_base.c	\
			my_itoab.c	\
			my_uitoab.c	\
			my_ltoab.c	\
			my_ftoa.c

# -_- Files located in $(FILE_D) = ./src/file/ -_-
FILE_F	=	open_file.c	\
			get_file_size.c	\
			get_file_content.c	\
			read_file.c

# -_- Files located in $(MY_PRINTF_D) = ./src/printf/ -_-
MY_PRINTF_F	=	my_printf.c	\
				parser.c

# -_- Files located in $(MY_PRINTF_UTILS_D) = ./src/printf/utils/ -_-
MY_PRINTF_UTILS_F	=	my_put_float_hex.c \
						my_put_scientific.c \
						my_put_adress.c

# -_- Files located in $(MY_PRINTF_PARAM_D) = ./src/printf/src/parameters/ -_-
MY_PRINTF_PARAM_F	=	parameter_int.c \
						parameter_o.c \
						parameter_x.c \
						parameter_f.c \
						parameter_e.c \
						parameter_g.c \
						parameter_a.c \
						parameter_chars.c \
						parameter_p.c \
						parameter_n.c

# -_- Files located in $(MY_PRINTF_MODIFIER_D) = ./src/printf/src/modifiers/ -_-
MY_PRINTF_MODIFIER_F	=	precision.c \
							width.c	\
							signs.c	\
							sharp.c

# -_- Files located in $(NODE_LL_D) = ./src/linked_lists/node/ -_-
NODE_LL_F	=	create.c	\
				destroy.c

# -_- Files located in $(SIMPLE_LL_D) = ./src/linked_lists/simple/ -_-
SIMPLE_LL_F	=	create.c	\
				add.c	\
				get.c	\
				dump.c	\
				pop.c	\
				destroy.c

# -_- Files located in $(DOUBLE_LL_D) = ./src/linked_lists/double/ -_-
DOUBLE_LL_F	=	create.c	\
				add.c	\
				get.c	\
				dump.c	\
				pop.c	\
				destroy.c

# -_- Files located in $(HASHTABLE_D) = ./src/hashtable/ -_-
HASHTABLE_F	=	create.c	\
				insert.c	\
				pop.c	\
				get.c	\
				dump.c	\
				hash.c	\
				destroy.c

# -_- Files located in $(SRC_D) = ./src/ -_-
SRC	=	$(addprefix $(IO_D), $(IO_F)) 	\
		$(addprefix $(COMPARAISON_D), $(COMPARAISON_F))	\
		$(addprefix $(CONVERT_D), $(CONVERT_F))	\
		$(addprefix $(MANIPULATION_D), $(MANIPULATION_F))	\
		$(addprefix $(SEARCH_D), $(SEARCH_F))	\
		$(addprefix $(WORD_ARRAY_D), $(WORD_ARRAY_F))	\
		$(addprefix $(UTILS_D), $(UTILS_F))	\
		$(addprefix $(MATH_D), $(MATH_F))	\
		$(addprefix $(FILE_D), $(FILE_F))	\
		$(addprefix $(MY_PRINTF_D), $(MY_PRINTF_F))	\
		$(addprefix $(MY_PRINTF_UTILS_D), $(MY_PRINTF_UTILS_F))	\
		$(addprefix $(MY_PRINTF_PARAM_D), $(MY_PRINTF_PARAM_F))	\
		$(addprefix $(MY_PRINTF_MODIFIER_D), $(MY_PRINTF_MODIFIER_F))	\
		$(addprefix $(NODE_LL_D), $(NODE_LL_F))	\
		$(addprefix $(SIMPLE_LL_D), $(SIMPLE_LL_F))	\
		$(addprefix $(DOUBLE_LL_D), $(DOUBLE_LL_F))	\
		$(addprefix $(HASHTABLE_D), $(HASHTABLE_F))

# -_- puts all .c files wherever they come from into the bin folder as a .o -_-
OBJ	=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

DEP	=	$(OBJ:.o=.d)

##	## --__-- PROGRESS BAR LOGIC --__--
##	TOTAL_FILES := $(words $(SRC))
##	CUR_FILE := .cur_file
##	BAR_WIDTH   := 40
##
##	define draw_bar
##		@if [ ! -f $(CUR_FILE) ]; then echo 0 > $(CUR_FILE); fi
##		@COUNT=$$(($$(cat $(CUR_FILE)) + 1)); \
##		echo $$COUNT > $(CUR_FILE); \
##		PERCENT=$$(($$COUNT * 100 / $(TOTAL_FILES))); \
##		FILLED=$$(($$COUNT * $(BAR_WIDTH) / $(TOTAL_FILES))); \
##		EMPTY=$$(($(BAR_WIDTH) - $$FILLED)); \
##		printf "\r\033[1;36m[%3d%%]\033[0m \033[1;32m[" $$PERCENT; \
##		printf '%.0s#' $$(seq 1 $$FILLED); \
##		printf '%.0s-' $$(seq 1 $$EMPTY); \
##		printf "]\033[0m Compiling: \033[0;33m%s\033[0m\033[K" "$$PERCENT" "$1"
##	endef

## --__-- RULES --__--

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar -rc $@ $^
#	@rm -f $(CUR_FILE)
	@printf "\033[1;32mBuild Complete!\033[0m\n"

# -_- Creates the bin dir if non existent (only once) -_-
$(OBJ_D):
	@mkdir -p $@

# -_- Compiles .o files into bin folder from all c files in the VPATH directories -_-
$(OBJ_D)%.o:	$(SRC_D)%.c | $(OBJ_D)
	@mkdir -p $(dir $@)
	@$(CC) -o $@ -c $< $(CFLAGS)
#	$(call draw_bar, $<)

clean:
	@rm -rf $(OBJ_D)
#	@rm -f $(CUR_FILE)
	@printf "\033[1;31mObjects cleaned.\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[1;31mBinary cleaned.\033[0m\n"

re: fclean $(NAME)

bestre:
	$(MAKE) fclean
	$(MAKE) -j$$(nproc)

-include $(DEP)

.PHONY:	all	clean	fclean	re	bestre
