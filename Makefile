NAME			= cub3D

CC				= gcc
RM				= rm -rf
CFLAGS		= -Wall -Wextra -Werror
SFLAGS    = #-g3 -fsanitize=address
MFLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit
INC_LINK 	= -I./libft -I./includes -I../gnl -I./mlx

MLX				= libmlx.a
MLX_LIB		= ./mlx
LIBFT 		= libft.a
LIBFT_LIB = ./libft

SRCS			=	./gnl/get_next_line.c \
						./gnl/get_next_line_utils.c \
						./src/parsing/dfs.c \
						./src/parsing/parsing_e.c \
						./src/parsing/parsing_e_r_text.c \
						./src/parsing/parsing_e_rgb.c \
						./src/parsing/parsing_m_check.c \
						./src/parsing/parsing_m_convert.c \
						./src/parsing/parsing_m_trim.c \
						./src/parsing/parsing_m.c \
						./src/parsing/parsing.c \
						./src/raycasting/game_init.c \
						./src/raycasting/game_init2.c \
						./src/raycasting/raycasting.c \
						./src/raycasting/texture.c \
						./src/raycasting/sprite.c \
						./src/raycasting/sprite_draw.c \
						./src/bonus/parsing_bonus.c \
						./src/bonus/raycasting_bonus.c \
						./src/bonus/luminosity.c \
						./src/bonus/mouse.c \
						./src/bonus/hud.c \
						./src/bonus/bgm.c \
						./src/bonus/points.c \
						./src/bonus/lifebar.c \
						./src/error_message.c \
						./src/utils_one.c \
						./src/save.c \
						./src/exit.c \
						./cub3d.c \
						./main.c

DEFT			= ./src/keys.c \
						./src/parsing/parse_init.c

BONUS			= ./src/bonus/keys_bonus.c \
						./src/bonus/keys_bonus2.c \
						./src/bonus/parse_init_bonus.c

OBJS			= $(SRCS:.c=.o)
OBJS_D		= $(DEFT:.c=.o)
OBJS_B		= $(BONUS:.c=.o)

all:			$(NAME)
$(NAME):		$(OBJS) $(OBJS_D) $(MLX) libft
	@cp $(LIBFT_LIB)/$(LIBFT) $(LIBFT)
	@$(CC) -o $(NAME) $(CFLAGS) $(MFLAGS) $(SFLAGS) $(INC_LINK) $(OBJS) $(OBJS_D) $(LIBFT)
	@$(RM) $(LIBFT)

bonus:		fclean $(OBJS) $(OBJS_B) $(MLX) libft
	@cp $(LIBFT_LIB)/$(LIBFT) $(LIBFT)
	@$(CC) -o $(NAME) $(CFLAGS) $(MFLAGS) $(SFLAGS) $(INC_LINK) $(OBJS) $(OBJS_B) $(LIBFT)
	@$(RM) $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

#MLX compile
$(MLX):
	@$(MAKE) -C $(MLX_LIB) all

#libft compile
libft:
	@$(MAKE) -C $(LIBFT_LIB) all

clean:
	@$(MAKE) -C $(MLX_LIB) clean
	@$(MAKE) -C $(LIBFT_LIB) clean
	@$(RM) $(OBJS) $(OBJS_D) $(OBJS_B)

fclean:			clean
	@$(MAKE) -C $(LIBFT_LIB) fclean
	@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft bonus
