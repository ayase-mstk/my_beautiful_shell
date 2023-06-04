NAME = minishell

SRCS_DIR = srcs/
SRCS =	\
	error.c \
	filepath.c \
	main.c

OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

LIBFT_DIR = libft/
PRINTF_DIR = libftprintf/
LIBS = -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -rf

A := $(shell brew --prefix readline)/include
B := $(brew --prefix readline)/include

all: $(OBJ_DIR) $(NAME)

test:
	@echo A is $(A)
	@echo B is $(B)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I $(shell brew --prefix readline)/include -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -lreadline -L $(shell brew --prefix readline)/lib -I $(shell brew --prefix readline)/include -o $(NAME) $(OBJS) $(LIBS)

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