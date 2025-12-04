# Makefile
NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes -I./libft/include

SRCDIR = src
OBJDIR = obj

SRCS = $(addprefix $(SRCDIR)/, \
	pipex.c init_data.c init_data_utils.c exec_pipe.c error_and_clear.c)

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIBFT = libft/libft.a

# Colors
GREEN = \033[0;32m
CYAN = \033[0;36m
RESET = \033[0m

all: $(NAME)

$(LIBFT):
	@echo "$(CYAN)Compiling libft...$(RESET)"
	@make -C libft

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(CYAN)Compiling...$(RESET)\r"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✓ Pipex compiled successfully!$(RESET)"

clean:
	@make clean -C libft
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)✓ Object files cleaned$(RESET)"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "$(GREEN)✓ All cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re