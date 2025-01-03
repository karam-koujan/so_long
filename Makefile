Name = so_long

OBJ = main.o ft_printf.o ft_putunbr_base.o ft_putaddress.o \
	  ft_strlen.o ft_putnbr.o ft_putchar.o ft_putstr.o ft_strchr.o \
	  get_next_line.o get_next_line_utils.o map.o map_validity.o map_utils.o map_render.o

TEST = test.o ft_printf.o ft_putunbr_base.o ft_putaddress.o \
	  ft_strlen.o ft_putnbr.o ft_putchar.o ft_putstr.o ft_strchr.o \
	  get_next_line.o get_next_line_utils.o map.o map_validity.o map_utils.o
all: $(Name)

$(Name): $(OBJ)
	$(CC) -g -l mlx -L . -framework OpenGL -framework Appkit $(OBJ) -o $(Name)

%.o: %.c so_long.h ft_printf.h get_next_line.h
	$(CC) -Wall  -Wextra -Werror -g -Imlx -c $< -o $@

test:  $(TEST) so_long.h ft_printf.h get_next_line.h
	$(CC)  $(TEST) -o test 
clean: 
	rm -f $(OBJ) $(TEST);
fclean : clean
	rm -f $(Name) 
re: clean all