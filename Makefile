NAME		= libftprintf.a
CFLAGS = -Wall -Wextra -Werror
HEADERS		= ft_printf.h
SRC = \
		ft_strlen.c ft_format_input_spec.c ft_format_p.c ft_format_precision.c \
		ft_len.c ft_format.c ft_input.c ft_memset.c ft_parce_flags.c ft_parcer_precision.c ft_parcer_widht.c \
		ft_printf.c ft_parcer_specifier.c ft_parcer_null.c ft_precision.c ft_print_address_p.c \
		format_widht_ch_str.c ft_print_lower_x.c ft_print_string.c ft_print_upper_x.c ft_print_u.c ft_parcer_minus.c \
		format_zero.c ft_printf_char.c ft_printf_i_d.c ft_putstr_len.c ft_read_file.c ft_format_null_str.c \
		ft_atoi.c ft_res0_init.c ft_specifier_c.c ft_specifier_i_d.c ft_specifier_lower_x.c ft_specifier_p_address.c \
		ft_bzero.c ft_specifier_s.c ft_specifier_u.c ft_specifier_upper_x.c ft_strdel.c ft_diff_format.c format_minus.c \
		ft_flags.c ft_strnew.c ft_subjoin.c ft_substr.c ft_type_solve.c ft_widht.c ft_printf_i_d.c ft_strcmp.c format_spec_id_pre.c \
		ft_printf.c 

OBJ = ${SRC:.c=.o}
DEP = ${OBJ:.o=.d}
RM = rm -f
CC = gcc
AR = ar rcs

all: $(NAME)

bonus: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

${NAME}: ${OBJ}
	ar rcs ${NAME} $?

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re

-include ${DEP}