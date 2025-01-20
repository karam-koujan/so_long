Name = so_long
BONUS_NAME = so_long_bonus
OBJ = ./mandatory/main.o ./mandatory/ft_printf.o ./mandatory/ft_putunbr_base.o ./mandatory/ft_putaddress.o \
	  ./mandatory/ft_strlen.o ./mandatory/ft_putnbr.o ./mandatory/ft_putchar.o ./mandatory/ft_putstr.o ./mandatory/ft_strchr.o \
	  ./mandatory/get_next_line.o ./mandatory/get_next_line_utils.o ./mandatory/map.o ./mandatory/map_validity.o ./mandatory/map_utils.o ./mandatory/map_render.o \
	  ./mandatory/game.o ./mandatory/ft_itoa.o ./mandatory/bonus_utils.o ./mandatory/key_event.o ./mandatory/ft_split.o ./mandatory/ft_strncmp.o ./mandatory/ft_substr.o \
	  ./mandatory/clean_up.o

BONUS = ./bonus/main_bonus.o ./bonus/ft_printf_bonus.o ./bonus/ft_putunbr_base_bonus.o ./bonus/ft_putaddress_bonus.o \
	  ./bonus/ft_strlen_bonus.o ./bonus/ft_putnbr_bonus.o ./bonus/ft_putchar_bonus.o ./bonus/ft_putstr_bonus.o ./bonus/ft_strchr_bonus.o \
	  ./bonus/get_next_line_bonus.o ./bonus/get_next_line_utils_bonus.o ./bonus/map_bonus.o ./bonus/map_validity_bonus.o ./bonus/map_utils_bonus.o ./bonus/map_render_bonus.o \
	  ./bonus/game_bonus.o ./bonus/ft_itoa_bonus.o ./bonus/bonus_utils_bonus.o ./bonus/key_event_bonus.o ./bonus/ft_split_bonus.o ./bonus/ft_strncmp_bonus.o ./bonus/ft_substr_bonus.o \
	  ./bonus/clean_up_bonus.o


all: $(Name)

$(Name): $(OBJ)
	$(CC)  -l mlx -L . -framework OpenGL -framework Appkit $(OBJ) -o $(Name)


bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS)
	$(CC) -l mlx -L . -framework OpenGL -framework Appkit $(BONUS) -o $(BONUS_NAME)

./bonus/%.o: ./bonus/%.c ./bonus/so_long_bonus.h ./bonus/ft_printf_bonus.h ./bonus/get_next_line_bonus.h
	$(CC)  -Wall  -Wextra -Werror -Imlx -c $< -o $@

./mandatory/%.o: ./mandatory/%.c ./mandatory/so_long.h ./mandatory/ft_printf.h ./mandatory/get_next_line.h
	$(CC)  -Wall  -Wextra -Werror -Imlx -c $< -o $@

clean: 
	rm -f $(OBJ) $(BONUS);
fclean : clean
	rm -f $(Name)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: clean