NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_putnb_hex.c \
	ft_putnb.c \
	ft_putnbr_unsign.c \
	ft_putstr.c \
	ft_putchar.c \
	ft_putnb_prt.c	

OBJS = ${SRCS:.c=.o}

INCLUDES = ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o:%.c ${INCLUDES}
	${CC} ${CFLAG} -c $< -o $@

all : ${NAME} 

${NAME}: ${OBJS} 
	ar rcs ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY:	all clean fclean re 

