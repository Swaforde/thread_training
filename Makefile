NAME = program
SRCS = src/main.c
OBJS = $(addprefix OBJ/, $(notdir $(SRCS:.c=.o)))
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = OBJ

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME) -G3

$(OBJ_DIR)/%.o : src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all