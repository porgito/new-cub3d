NAME					= cub3D

BUILD_DIR				= build/

HEADER_DIR				= inc/

HEADER_FILES				= inc/cub3d.h inc/typedef.h

DIR						= src/

SRC			 			=	main.c	init.c	init_textures.c	utils.c	keypress.c	free.c\
							parsing/parsing.c	parsing/colors.c	parsing/check_map.c parsing/lst_utils.c\
							raycasting/draw_minimap.c		raycasting/move.c\
							raycasting/refresh.c	raycasting/draw_rays.c\
							raycasting/raycasting.c  raycasting/texture.c \
							
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)

LIBFT					= libft.a
LIB_DIR					= libft/



CC						= cc
CFLAGS					= -Wall -Wextra -Werror
SANITIZE				= $(CFLAGS) -fsanitize=address

RM 						= rm -rf

OS := $(shell uname -s)

ifeq ($(OS), Darwin)
	MINILIB_DIR				= mlx/
	MINILIB_FLAGS			= -framework OpenGL -framework AppKit
else
    MINILIB_DIR			= minilibx_linux/
    MINILIB_FLAGS 		= -Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz 
endif

MINILIB					= libmlx.a

$(BUILD_DIR)%.o:		$(DIR)%.c ${HEADER_FILES} ${LIB_DIR}*.c ${LIB_DIR}/${LIB_HEADER} ${LIB_DIR} Makefile 
						@mkdir -p $(@D)
						$(CC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -c $< -o $@

all: 					lib mkbuild $(HEADER_DIR) $(NAME)

go:						all
						./${NAME} map.cub

mkbuild:	
						@mkdir -p ${BUILD_DIR}

						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(CC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(MINILIB_FLAGS)

sanitize :				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(CC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(MINILIB_FLAGS)

lib:
						@make -C $(LIB_DIR) --no-print-directory
	
clean:					
						@${RM} $(OBJECTS)
						@make clean -C $(LIB_DIR) --no-print-directory
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR) --no-print-directory

re:						fclean all
						$(MAKE) all

.PHONY:     			all $(NAME) mkbuild lib clean fclean re sanitize