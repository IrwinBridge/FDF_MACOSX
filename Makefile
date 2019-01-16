NAME = fdf
SRC = *.c
LIBFT = libft/*.c
LIBLINK = -L./libft -lft
MLXLINK = -L./minilibx -lmlx -framework OpenGL -framework AppKit
MATHLINK = -lm
GFLAGS = -Wall -Wextra -Werror

$(NAME):
	make -C libft
	make -C minilibx
	gcc $(GFLAGS) $(SRC) $(MLXLINK) $(LIBLINK) $(MATHLINK) -Ofast -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f libft/*.o
	/bin/rm -f minilibx/*.o

fclean: clean
	/bin/rm -f libft/libft.a
	/bin/rm -f minilibx/libmlx.a
	/bin/rm -f $(NAME)

re: fclean all
