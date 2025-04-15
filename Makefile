NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes
LIBFT_DIR = ./libft
SRC_DIR		= ./src/
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(INCLUDES)

# Source files and object files
SRC_FILES	= minishell
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(SRC:.c=.o)

# Main target
all: $(NAME)

# To link with the required internal Linux API:
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -lreadline -o $(NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBFT_INC)

# Compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean object files
clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

# Clean object files and executables
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Recompile everything
re: fclean all
	make re -C $(LIBFT_DIR)
