NAME = minishell

SRCS_DIR = ./srcs/
SRCS =	\
	error.c \
	filepath.c \
	main.c

OBJ_DIR = ./obj/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

# DEPS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.d))

LIBFT = libft/libft.a
LIBFT_DIR = libft/
PRINTF = libftprintf/libftprintf.a
PRINTF_DIR = libftprintf/
LIBS = $(LIBFT) $(PRINTF)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -rf

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -lreadline -o $(NAME) $(OBJS) $(LIBS)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all fclean clean re