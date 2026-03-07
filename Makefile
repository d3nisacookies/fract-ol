NAME	= fractol

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

MLX_DIR	= mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES = -Iincludes -I$(MLX_DIR)

SRC_DIR	= src

SRCS	= $(SRC_DIR)/main.c \
		  $(SRC_DIR)/init.c \
		  $(SRC_DIR)/draw.c \
		  $(SRC_DIR)/mandelbrot.c \
		  $(SRC_DIR)/julia.c \
		  $(SRC_DIR)/mouse.c \
		  $(SRC_DIR)/events.c \
		  $(SRC_DIR)/utils.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re