

SRCS=push_wap.c sort.c utils.c stack.c instructions.c error_handling.c


libft = libft.a



name=push_swap


$(name): $(SRCS)
	cc $(SRCS) $(libft) -o $(name)