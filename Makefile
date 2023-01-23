

SRCS=push_swap.c sort.c utils.c stack.c instructions.c error_handling.c \
	sort_five.c sort_three.c sort2.c instructions2.c utils2.c sort_any.c parsing_utils.c


libft = libft.a



name=push_swap


$(name): $(SRCS)
	cc $(SRCS) $(libft) -o $(name)


# all:
# 	@make -s -C libft 