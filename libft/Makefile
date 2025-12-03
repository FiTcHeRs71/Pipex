# File Name
NAME = libft.a

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = object

# Source files
SRCS_BASIC = $(addprefix $(SRCDIR)/Basic_fonctions/, \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c \
	ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
	ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c)

SRCS_PRINTF = $(addprefix $(SRCDIR)/ft_printf/, \
	ft_print_char.c ft_printf.c ft_print_int.c ft_print_void.c)

SRCS_GNL = $(addprefix $(SRCDIR)/get_next_line/, \
	get_next_line.c get_next_line_utils.c)

SRCS = $(SRCS_BASIC) $(SRCS_PRINTF) $(SRCS_GNL)

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Flags
CC = gcc
AR = ar rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I$(INCDIR) -I$(INCDIR)/ft_printf -I$(INCDIR)/get_next_line

# Colors
GREEN = \033[0;32m
CYAN = \033[0;36m
RESET = \033[0m

all: $(NAME)
	@echo "$(GREEN) 🎉 libft.a ready 🎉 $(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(CYAN)Compiling...$(RESET)\r"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✓ Archive libft created: $(NAME)$(RESET)"

clean:
	@$(RM) $(OBJDIR)
	@echo "$(CYAN)✓ Object files libft removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)✓ $(NAME) libft.a removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re