NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM			= rm -f
LIBFT_PATH  = ./libft
LIBFT       = $(LIBFT_PATH)/libft.a

SRCS        = ft_printf.c \
              alphabetic_writers.c \
              numeric_writers.c \
              hexadecimal_writers.c \
OBJS        = $(SRCS:.c=.o)

BONUS_DIR   = ./bonus
SRCS_BONUS  = $(BONUS_DIR)/ft_printf_bonus.c \
			  $(BONUS_DIR)/flags_bonus.c \
              $(BONUS_DIR)/alphabetic_writers_bonus.c \
			  $(BONUS_DIR)/numeric_writers_bonus.c \
			  $(BONUS_DIR)/hexadecimal_writers_bonus.c \
			  $(BONUS_DIR)/utils_bonus.c
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_PATH) -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_PATH) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.h .
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

bonus: .bonus_done

.bonus_done: $(OBJS_BONUS)
	make -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.h .
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS_BONUS)
	touch .bonus_done

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) .bonus_done

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	$(RM) libft.h
	$(RM) .bonus_done

re: fclean all

.PHONY: all clean fclean re
