NAME        =	libftprintf.a
CC          =	cc
CFLAGS      = 	-Wall -Wextra -Werror
RM          = 	rm -f
AR          = 	ar rcs

LIBFT_PATH  = 	./libft
LIBFT       = 	$(LIBFT_PATH)/libft.a

SRCS        =	ft_printf.c \
				alphabetic_writers.c \
				numeric_writers.c \
				hexadecimal_writers.c
OBJS        = 	$(SRCS:.c=.o)

BONUS_DIR   = 	./bonus
SRCS_BONUS  = 	$(BONUS_DIR)/ft_printf_bonus.c \
				$(BONUS_DIR)/flags_bonus.c \
              	$(BONUS_DIR)/alphabetic_writers_bonus.c \
				$(BONUS_DIR)/numeric_writers_bonus.c \
              	$(BONUS_DIR)/hexadecimal_writers_bonus.c \
				$(BONUS_DIR)/utils_bonus.c
OBJS_BONUS  = 	$(SRCS_BONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_PATH) -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_PATH) -I$(BONUS_DIR) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.h .
	$(RM) $(NAME)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	$(RM) .bonus_done

bonus:	.bonus_done

.bonus_done:	$(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.h .
	$(RM) $(NAME)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS_BONUS)
	@touch .bonus_done

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) .bonus_done

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	$(RM) libft.h

re: fclean all

.PHONY: all clean fclean re bonus
