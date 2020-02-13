gcc -fsanitize=address -Wextra -Wall -Iminilibx -framework OpenGL -framework AppKit -g3 cub3d.h srcs/*.c srcs/get_next_line/*.c srcs/get_next_line/get_next_line.h libmlx.a  && ./a.out labyrinthe.cub
