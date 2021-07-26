NAME = so_long

HEADER = so_long.h

SRCS	= main.c \
		parsing_stepa.c \
		check_valid.c \
		comp_str_add.c
		
LIBA = ./libft_42_school/libft.a

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

STRJOIN = ./libft_42_school/ft_strjoin.c \
		./libft_42_school/ft_strlen.c \
		./libft_42_school/ft_strdup.c \
		./libft_42_school/ft_split.c \

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}
	
all: ${NAME}
	
${NAME}:	${OBJS} ${HEADER}
			gcc -g -o ${NAME} ${OBJS} ${LIBA}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} a.out

test: 		${HEADER}
			gcc -g ${SRCS} ${STRJOIN}
			${RM} ${OBJS}

tclean: fclean test

re:		fclean all

.PHONY: re clean fclean all test tclean