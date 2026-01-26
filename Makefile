NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
LIBFT_PATH  = ./libft
LIBFT       = $(LIBFT_PATH)/libft.a

SRCS        = ft_printf.c \
              alphabetic_writers.c \
              numeric_writers.c \
              hexadecimal_writers.c

OBJS        = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -I./libft -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
