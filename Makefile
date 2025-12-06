# Makefile
NAME = pipex
NAME_BONUS = pipex_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./include -I./libft/include

SRCDIR = src
SRC_BONUS_DIR = bonus
OBJDIR = obj
OBJDIR_BONUS = obj_bonus

SRCS = $(addprefix $(SRCDIR)/, \
	pipex.c init_data.c init_data_utils.c exec_pipe.c error_and_clear.c)

SRCS_BONUS = $(addprefix $(SRC_BONUS_DIR)/, \
	pipex_bonus.c init_data_bonus.c init_data_utils_bonus.c exec_pipe_bonus.c error_and_clear_bonus.c)

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJDIR_BONUS)/%.o)

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

$(OBJDIR_BONUS):
	@mkdir -p $(OBJDIR_BONUS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(CYAN)Compiling...$(RESET)\r"

$(OBJDIR_BONUS)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJDIR_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(CYAN)Compiling bonus...$(RESET)\r"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✓ Pipex compiled successfully!$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "$(GREEN)✓ Pipex bonus compiled successfully!$(RESET)"

clean:
	@make clean -C libft
	@rm -rf $(OBJDIR) $(OBJDIR_BONUS)
	@echo "$(GREEN)✓ Object files cleaned$(RESET)"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)✓ All cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus