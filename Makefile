# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 16:00:14 by aamhamdi          #+#    #+#              #
#    Updated: 2023/01/24 12:59:29 by aamhamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# paths
SRC_PATH   = src/
B_PATH     = checker_bonus/
OBJ_PATH   = build/
G_PATH     = gnl/
LIBFT_PATH = libft/

# srcs
SRC   = push_swap.c sort.c utils.c stack.c instructions.c parsing.c sort_five.c sort_three.c sort2.c instructions2.c utils2.c sort_any.c parsing_utils.c
B_SRC = bonus_instructions.c bonus_instructions2.c bonus_parsing.c bonus_utils.c checker.c handle_stack.c 
G_SRC = get_next_line.c get_next_line_utils.c

# get next line objects
G_SRCS= $(addprefix $(G_PATH), $(G_SRC))
G_OBJ=$(G_SRC:.c=.o)
G_OBJS=$(addprefix $(OBJ_PATH), $(G_OBJ))

# push swap objects
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ  = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

# checker objects
B_SRCS = $(addprefix $(B_PATH), $(B_SRC))
B_OBJ  = $(B_SRC:.c=.o)
B_OBJS = $(addprefix $(OBJ_PATH), $(B_OBJ))

# names
LIBFT        = libft.a
NAME         = push_swap
CHECKER_NAME = checker

# headers
PUSH_SWAP_H = push_swap.h

FLAGS= -Wall -Wextra -Werror

all:$(OBJ_PATH) $(NAME) 
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(SRC_PATH)$(PUSH_SWAP_H)
	cc $(FLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(B_PATH)%.c
	cc $(FLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(G_PATH)%.c
	cc $(FLAGS) -c $< -o $@
	
$(LIBFT):
	@make -s -C $(LIBFT_PATH)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)
	
$(NAME): $(OBJS) $(LIBFT)
	cc $(OBJS) $(LIBFT_PATH)$(LIBFT) -o $(NAME)
	
clean:
	rm -rf $(OBJ_PATH)
	make clean -s -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME) $(CHECKER_NAME) $(LIBFT_PATH)$(LIBFT)

bonus: $(OBJ_PATH) $(B_OBJS) $(LIBFT) $(G_OBJS)
	cc $(B_OBJS) $(G_OBJS) $(LIBFT_PATH)$(LIBFT) -o $(CHECKER_NAME)

re: fclean all
