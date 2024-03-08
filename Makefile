

# Makefile for thorange project

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g #-Wall -Wextra -Werror

# Source files
SRCS = $(wildcard *.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
NAME = orange

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Rule to clean the object files
clean:
	rm -f $(OBJS)

# Rule to clean the executable and object files
fclean: clean
	rm -f $(NAME)

# Rule to recompile the project
re: fclean all

# Rule to compile the project
all: $(NAME)

.PHONY: all clean fclean re
