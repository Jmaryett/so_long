NAME = so_long

HEADER = so_long.h 
#		./mlx/mlx.h

SRCS	= main.c \
		parsing_stepa.c \
		check_valid.c \
		comp_str_add.c 
		#./mlx/*.c
		
LIBA = ./libft_42_school/libft.a

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

STRJOIN = ./libft_42_school/ft_strjoin.c \
		./libft_42_school/ft_strlen.c \
		./libft_42_school/ft_strdup.c \
		./libft_42_school/ft_split.c

# %.o: %.c
# ${CC} ${CFLAGS} -Imlx -c $< -o $@ 

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
all: ${NAME}
	
${NAME}: ${OBJS} ${HEADER}
		 ${CC} -g -o ${NAME} ${OBJS} ${LIBA}

# ${NAME}: ${OBJS}
#		${CC} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

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