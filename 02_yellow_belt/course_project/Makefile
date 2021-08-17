SRCS_SUFFIX	= .cpp

SRCS_DIR	= srcs/

SRCS		= $(shell find $(SRCS_DIR) -name "*$(SRCS_SUFFIX)")

OBJS		= $(SRCS:$(SRCS_SUFFIX)=.o)

HEAD		= includes/

NAME		= project.out

TAR			= cource_project_yellow.tar

CC			= g++
CFLAGS		= --std=c++17

RM			= rm -f

all				: $(NAME) tar

obj				: $(OBJS)

tar				: $(TAR)

$(SRC_DIR)%.o 	: $(SRC_DIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD)

$(NAME)			: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(TAR)			:
	tar -cvf $(TAR) $(SRCS_DIR)*$(SRCS_SUFFIX) $(HEAD)*

clean			:
	$(RM) $(OBJS)

fclean			: clean
	$(RM) $(NAME)
	$(RM) $(TAR)

re				: fclean all

.PHONY	 		: all obj tar clean fclean re
