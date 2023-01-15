

SRCS = push_swap.c sort.c utils.c stack.c instructions.c error_handling.c


libft = /libft/libft.a
libft_h = /libft/libft.h



name=push_swap


$(name): $(SRCS) libft_h
	cc $(SRCS) libft -o $(name)