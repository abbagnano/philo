NAME	=	philo
CFLAGS	=	-Wall -Wextra #-Werror
OBJS	=	ft_exit.o \
			ft_start.o \
			philo.o \
			utils_basic.o \
			utils_start.o		

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	gcc $(CFLAGS) $^ -o $@ -pthread

%.o		:	%.c
	gcc $(CFLAGS) -c $^

clean	:
	rm -rf	$(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

PHONY	:	all clean fclean re
