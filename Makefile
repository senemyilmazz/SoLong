SRCS = 	./SRC/main.c \
		./SRC/get_next_line.c \
		./SRC/map_validity.c \
		./SRC/path_validity.c \
		./SRC/create_window.c \
		./SRC/steps.c

SRCB =  ./SRC_BONUS/main.c \
		./SRC_BONUS/get_next_line.c \
		./SRC_BONUS/map_validity.c \
		./SRC_BONUS/path_validity.c \
		./SRC_BONUS/create_window.c \
		./SRC_BONUS/steps.c \
		./SRC_BONUS/sprite.c
		

OBJS = ${SRCS:.c=.o}
OBJB = ${SRCB:.c=.o}

LIB = ./libft/libft.a
NAME = so_long
NAMEB = so_long_bonus
NAMEmlx = ./mlx/libmlx.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
MFLAGS = -framework OpenGL -framework AppKit 
RM = rm -rf


all : ${LIB} ${NAME} ${NAMEmlx}

${LIB}:
	@make -C ./libft

${NAMEmlx}:
	@make -C ./mlx

${NAME}: ${OBJS} ${LIB} ${NAMEmlx}
	@${CC} ${CFLAGS} ${MFLAGS} ${OBJS} ${NAMEmlx} ${LIB} -o ${NAME}

bonus : ${LIB} ${NAME} ${NAMEB}

${NAMEB}: ${OBJB} ${LIB} ${NAMEmlx}
	@${CC} ${CFLAGS} ${MFLAGS} ${OBJB} ${NAMEmlx} ${LIB} -o ${NAMEB}

%.o: %.c
	@${CC} ${CFLAGS} -Imlx -c $< -o $@

clean:
	@${RM} ${NAME} ${OBJS} ${OBJB}

fclean: clean
	@${RM} ${NAME} ${OBJS} ${OBJB} ${NAMEB}
	@make fclean -C ./libft
	@make clean -C ./mlx

re: fclean all bonus

.PHONY: all clean fclean re bonus