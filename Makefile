NAME = push_swap
CHECKER = checker

LIB = ./libft/libft.a
LIB_I = ./libft/

CFLAGS = -Wall -Werror -Wextra 

SRCS = main.c \
	utils.c \
	utils2.c \
	utils3.c \
	utils4.c \
	utils5.c \
	merge_sort.c \
	instruct.c \
	sort_small.c \
	sort_big.c \
	stack_operation.c \

SRCS_CHECKER = utils.c \
		utils2.c \
		utils3.c \
		utils4.c \
		merge_sort.c \
		instruct.c \
		instruct_checker.c \
		checker_utils.c \
		checker.c \

all: $(NAME)

libft:
	@make -C ./libft

$(NAME): libft
	@gcc -o $(NAME) $(CFLAGS) -g -I$(LIB_I) $(LIB) $(SRCS)

$(CHECKER):
	@make -C ./libft
	@gcc -o $(CHECKER) $(CFLAGS) -g -I$(LIB_I) $(LIB) $(SRCS_CHECKER)

norminette:
	norminette -R CheckForbiddenHeader *.h *.c

clean:
	@make fclean -C ./libft
	rm -rf *.dSYM $(NAME)
	rm -rf $(CHECKER)

fclean: clean

re: fclean all

bonus: all $(CHECKER)

.PHONY: all clean fclean re libft bonus
