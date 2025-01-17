Name = so_long

OBJ = main.o ft_printf.o ft_putunbr_base.o ft_putaddress.o \
	  ft_strlen.o ft_putnbr.o ft_putchar.o ft_putstr.o ft_strchr.o \
	  get_next_line.o get_next_line_utils.o map.o map_validity.o map_utils.o map_render.o \
	  game.o ft_itoa.o bonus_utils.o key_event.o ft_split.o ft_strncmp.o ft_substr.o

all: $(Name)

$(Name): $(OBJ)
	$(CC) -g -l mlx -L . -framework OpenGL -framework Appkit $(OBJ) -o $(Name)

%.o: %.c so_long.h ft_printf.h get_next_line.h
	$(CC) -g -Wall  -Wextra -Werror -Imlx -c $< -o $@

clean: 
	rm -f $(OBJ);
fclean : clean
	rm -f $(Name)

re: fclean all

.PHONY: clean