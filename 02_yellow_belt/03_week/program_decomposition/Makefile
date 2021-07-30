SRCS_SUFFIX	= .cpp

SRCS_DIR	= ./srcs

SRCS		= $(shell find $(SRCS_DIR) -name "*$(SRCS_SUFFIX)")

OBJS		= $(SRCS:$(SRCS_SUFFIX)=.o)

HEAD		= includes/

NAME		= buses

CC		= g++
CFLAGS		= -Wall -Wextra -Werror --std=c++17

RM		= rm -f

all		: $(NAME)

obj		: $(SRCS)

$(SRC_DIR)%.o 	: $(SRC_DIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD)

$(NAME)		: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean		:
	$(RM) $(OBJS)

fclean		: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY 		: all obj clean fclean re
