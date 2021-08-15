SRCS_SUFFIX	= .cpp

SRCS_DIR	= ./srcs

SRCS		= $(shell find $(SRCS_DIR) \( -name "*$(SRCS_SUFFIX)" -and \( ! -name "main.cpp" \) \))

OBJS		= $(SRCS:$(SRCS_SUFFIX)=.o)

HEAD		= includes/

NAME		= project.out

CC			= g++
CFLAGS		= --std=c++17

RM			= rm -f

all				: $(NAME)

obj				: $(OBJS)

$(SRC_DIR)%.o 	: $(SRC_DIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD)

$(NAME)			: $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS_DIR)/main.cpp -o $(SRCS_DIR)/main.o -I $(HEAD)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS_DIR)/main.o $(OBJS)

clean			:
	$(RM) $(OBJS)

fclean			: clean
	$(RM) $(NAME)

re				: fclean all

.PHONY	 		: all obj clean fclean re
