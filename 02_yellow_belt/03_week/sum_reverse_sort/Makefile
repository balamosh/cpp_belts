SRCS_SUFFIX	= .cpp

SRCS_DIR	= ./srcs

SRCS		= $(shell find $(SRCS_DIR) -name "*$(SRCS_SUFFIX)")

OBJS		= $(SRCS:$(SRCS_SUFFIX)=.o)

HEAD		= includes/

LIB		= $(SRC_DIR)libft.a

CC		= g++
CFLAGS		= -Wall -Wextra -Werror --std=c++17

RM		= rm -f

all		: $(LIB)

obj		: $(SRCS)

$(SRC_DIR)%.o 	: $(SRC_DIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD)

$(LIB)		: $(OBJS)
	ar rc $(LIB) $(OBJS)
	ranlib $(LIB)

clean		:
	$(RM) $(OBJS)
	$(RM) $(LIB)

fclean		: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY 		: all obj clean fclean re
