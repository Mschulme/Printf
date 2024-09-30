NAME	= libftprintf.a

SRC	=	ft_printf.c \
		ft_percent.c \
		ft_print_char.c \
		ft_print_string.c \
		ft_print_pointer.c \
		ft_print_integer.c \
		ft_print_unsigned.c \
		ft_print_hexlower.c \
		ft_print_hexupper.c \
		ft_prints.c \
		ft_printszero.c \
		ft_utils.c \
		ft_utils2.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

bonus: all

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re