NAME = push_swap

CFLAGS =  -Wall -Wextra -Werror -I./libft
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

PUSH_SWAP = a_stack_to_b.c \
				b_stack_to_a.c \
				cost_analysis.c \
				handle_errors.c \
				push_swap.c \
				push.c \
				rev_rotate.c \
				rotate.c \
				sort_stacks.c \
				sort_three.c \
				stack_init.c \
				stack_utils.c \
				swap_func.c \

OBJECTS = ${PUSH_SWAP:.c=.o}

%.o: %.c
	cc ${CFLAGS} -c $< -o $@

all: ${NAME} ${LIBFT}

${NAME}: ${OBJECTS} ${LIBFT}
	 cc ${CFLAGS} ${OBJECTS} -L$(LIBFT_DIR) -lft -o ${NAME} 

${LIBFT}:
	make -C libft
clean:
	rm -f ${OBJECTS} ${LIBFT}
	@make clean -C ./libft
fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re
