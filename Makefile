NAME = philo_bonus

HEADER = philo_bonus.h

LIST =	main_philo_bonus.c\
		philo_simulation_fanction_bonus.c\
		utils_philo_0_bonus.c\
		utils_philo_1_bonus.c\
		utils_philo_2_bonus.c\

OBJ = ${LIST:.c=.o}

FLAGS = -Wall -Wextra -Werror -pthread -include philo_bonus.h

all:

bonus: $(NAME)

%.o: %.c	$(HEADER)
			gcc $(FLAGS) -c $< -o $@

$(NAME):	$(HEADER) $(OBJ)
				gcc $(FLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus
