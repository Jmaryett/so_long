LIBA_C = ./libft/*.c

LIBA = libft.a

NAME = so_long

HEADER = so_long.h

SRCS	= main.c \
		1_parsing.c \
		2_check_valid.c \
		2_1_check_valid.c \
		3_add_comp_lines.c \
		4_error_cases.c \
		5_init_positions.c \
		6_relate_path.c \
		7_rendering_map.c \
		8_drawing_sprites.c \
		9_moving_checking.c \
		10_check_exit.c \
		my_key_hooks.c

MLX = libmlx.dylib
		
OBJS	= ${SRCS:.c=.o}

RM	= rm -f

AR 	= ar rc

CC	= gcc -g

CFLAGS	= -Wall -Wextra -Werror

STRJOIN = ./libft/ft_strjoin.c \
		./libft/ft_strlen.c \
		./libft/ft_strdup.c \
		./libft/ft_split.c

OBJS2	= ${STRJOIN:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
all: ${NAME}

compile_libft: ${LIBFT_A}

compile_mlx: ${MLX_A}

${MLX}:
			cd ./mlx; \
			make; \
			mv ${MLX} ../; \
			cd ./mlx; \
			make clean

${LIBA}: ${LIBA_C}
			cd ./libft; \
			make; \
			mv ${LIBA} ../; \
			cd ./libft; \
			make clean

${NAME}: ${LIBA} ${MLX} ${HEADER} ${OBJS} 
		${CC} ${CFLAGS} -framework  OpenGL -framework AppKit -o ${NAME} ${OBJS} ${LIBA} ${MLX}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} a.out ${LIBA} ${MLX}

test:	${HEADER} ${OBJS} ${OBJS2} ${MLX}
		${CC} ${CFLAGS} -framework OpenGL -framework AppKit -o ${NAME} ${OBJS} ${OBJS2} ${MLX}

tclean: fclean test

norm:
		norminette ${SRCS} ${HEADER}

re:		fclean all

.PHONY: re clean fclean all test tclean compile_libft compile_mlx norm