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

CFLAGS	=	-I$(INCLUDE) -I$(MY_PRINTF_INCLUDE) -g3 -Wall -Wextra

OBJ_D	=	$(ROOT_DIR)obj/

SRC_D	=	$(ROOT_DIR)src/

# -_- Directories located in $(SRC_D) = ./src/ -_-
IO_D	=	$(SRC_D)io/
STRING_D	=	$(SRC_D)string/
MATH_D	=	$(SRC_D)math/
UTILS_D	=	$(SRC_D)utils/
FILE_D	=	$(SRC_D)file/
MY_PRINTF_D	=	$(SRC_D)printf/

# -_- Directories located in $(STRING_D) = ./src/string/ -_-
COMPARAISON_D	=	$(STRING_D)comparaison/
CONVERT_D	=	$(STRING_D)convert/
MANIPULATION_D	=	$(STRING_D)manipulation/
SEARCH_D	=	$(STRING_D)search/
WORD_ARRAY_D	=	$(STRING_D)word_array/

# -_- Directories located in $(MY_PRINTF_D) = ./src/printf/ -_-
MY_PRINTF_UTILS_D	=	$(MY_PRINTF_D)utils/
MY_PRINTF_PARAM_D	=	$(MY_PRINTF_D)parameters/

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
			my_nbrlen.c

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
				switch_base_flag.c

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

# -_- Files located in $(SRC_D) = ./src/ -_-
SRC	=	$(addprefix $(IO_D), $(IO_F)) 	\
		$(addprefix $(COMPARAISON_D), $(COMPARAISON_F))	\
		$(addprefix $(CONVERT_D), $(CONVERT_F))	\
		$(addprefix $(MANIPULATION_D), $(MANIPULATION_F))	\
		$(addprefix $(SEARCH_D), $(SEARCH_F))	\
		$(addprefix $(WORD_ARRAY_D), $(WORD_ARRAY_F))	\
		$(addprefix $(MATH_D), $(MATH_F))	\
		$(addprefix $(UTILS_D), $(UTILS_F))	\
		$(addprefix $(FILE_D), $(FILE_F))	\
		$(addprefix $(MY_PRINTF_D), $(MY_PRINTF_F))	\
		$(addprefix $(MY_PRINTF_UTILS_D), $(MY_PRINTF_UTILS_F))	\
		$(addprefix $(MY_PRINTF_PARAM_D), $(MY_PRINTF_PARAM_F))	\

# -_- puts all .c files wherever they come from into the bin folder as a .o -_-
OBJ	=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

## --__-- RULES --__--

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -rc $@ $^

# -_- Creates the bin dir if non existent (only once) -_-
$(OBJ_D):
	mkdir -p $@

# -_- Compiles .o files into bin folder from all c files in the VPATH directories -_-
$(OBJ_D)%.o:	$(SRC_D)%.c | $(OBJ_D)
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bestre:
	make fclean
	make -j4

.PHONY:	all	clean	fclean	re	bestre
