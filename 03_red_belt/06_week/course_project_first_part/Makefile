NAME		= project

SRCS_DIR	= srcs/
HEAD_DIR	= includes/
BUILD_DIR	= build/

SRCS_FILES	= $(notdir $(shell find $(SRCS_DIR) -name "*.cpp"))

OBJS_FILES	= $(SRCS_FILES:.cpp=.o)

SRCS 		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS		= $(addprefix $(BUILD_DIR), $(OBJS_FILES))
DEPS		= $(OBJS:.o=.d)

CC			= g++
CFLAGS		= --std=c++17 -MMD -pthread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BUILD_DIR)%.o: $(SRCS_DIR)%.cpp $(BUILD_DIR)%.d
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(HEAD_DIR) -o $@ -c $<

$(BUILD_DIR)%.d: ;

$(DEPS):
-include $(wildcard $(DEPS))

clean: 
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
