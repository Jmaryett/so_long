LIBFT = -L libft -lft

LIBFT_C = ./libft_42_school/*.c

LIBFT_A = ./libft_42_school/libft.a

LIBA = libft.a

NAME = so_long

HEADER = so_long.h

SRCS	= main.c \
		1_parsing.c \
		2_check_valid.c \
		2_add_check_valid.c \
		3_add_comp_lines.c \
		4_invalid_map.c \
		5_init_positions.c \
		6_relate_path.c \
		7_drawing_sprites.c \
		my_key_hooks.c

MLX_A = ./mlx/libmlx.dylib

MLX = libmlx.dylib
		
OBJS	= ${SRCS:.c=.o}

RM	= rm -f

AR 	= ar rc

CC	= gcc -g

CFLAGS	= -Wall -Wextra -Werror

STRJOIN = ./libft_42_school/ft_strjoin.c \
		./libft_42_school/ft_strlen.c \
		./libft_42_school/ft_strdup.c \
		./libft_42_school/ft_split.c

 #%.o: %.c
#	 ${CC} ${CFLAGS} -Imlx -c $< -o $@ 

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
all: ${NAME}

compile_libft: ${LIBFT_A}

compile_mlx: ${MLX_A}

${MLX_A}:
			cd ./mlx; \
			make; \
			mv ${MLX} ../; \
			cd ./mlx; \
			make clean

${LIBFT_A}:
			cd ./libft_42_school; \
			make; \
			mv ${LIBA} ../; \
			cd ./libft_42_school; \
			make clean
	
#${NAME}: ${OBJS} ${HEADER}
#		 ${CC} -g -o ${NAME} ${OBJS} ${LIBA}

${NAME}: ${HEADER} ${OBJS} ${MLX} ${LIBA}
		${CC} ${CFLAGS} -framework OpenGL -framework AppKit -o ${NAME} ${OBJS} ${LIBA} ${MLX}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} a.out

test:	${HEADER} ${OBJS} ${LIBFT_A} ${MLX_A} ${MLX} ${LIBA}
		${CC} ${CFLAGS} -framework OpenGL -framework AppKit -o ${NAME} ${OBJS} ${LIBA} ${MLX}

tclean: fclean test

re:		fclean all

.PHONY: re clean fclean all test tclean compile_libft compile_mlx