# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 14:35:27 by dmdemirk          #+#    #+#              #
#    Updated: 2024/05/21 16:28:49 by dmdemirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

# Program
NAME			=	fdf	

# Comands
COMPILER		=	cc
DFLAGS			=	-g3 -gdwarf-2
CFLAGS			=	-Wall -Wextra -Werror $(DFLAGS)
MLXFLAGS 		=	-L$(LIB_DIR)/minilibx-linux -L/usr/lib -lmlx -lXext -lX11
AR				=	ar rcs
RM				=	rm -rf

# Structure
LIB_DIR					=	./lib
LIBFT					=	$(LIB_DIR)/libft/libft.a
MINILIBX_LIB			=	wget https://cdn.intra.42.fr/document/document/21665/minilibx-linux.tgz
MINILIBX				=	$(LIB_DIR)/minilibx-linux/libmlx_Linux.a

SRC_DIR					=	./src
APP_DIR					=	$(SRC_DIR)/app
COMMON_DIR				=	$(SRC_DIR)/common

INCLUDES				=	-I./inc \
							-I $(LIB_DIR)/libft/inc \
							-I $(LIB_DIR)/minilibx-linux \

MAIN_SOURCE				=	$(SRC_DIR)/main.c
APP_SOURCES				=	$(wildcard $(APP_DIR)/*.c)
COMMON_SOURCES			=	$(wildcard $(COMMON_DIR)/*.c)

SOURCES					=	$(MAIN_SOURCE) \
							$(APP_SOURCES) \
							$(COMMON_SOURCES)
# Building
BUILD_DIR				=	./build
MAIN_OBJECT				=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/src/%.o, $(MAIN_SOURCE))
APP_OBJECTS				=	$(patsubst $(APP_DIR)/%.c, $(BUILD_DIR)/src/app/%.o, $(APP_SOURCES))
COMMON_OBJECTS			=	$(patsubst $(COMMON_DIR)/%.c, $(BUILD_DIR)/src/common/%.o, $(COMMON_SOURCES))

OBJECTS					=	$(MAIN_OBJECT) \
							$(APP_OBJECTS) \
							$(COMMON_OBJECTS)

# Processing
all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS)
	@$(COMPILER) $(CFLAGS) $(OBJECTS) $(INCLUDES) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $@ -lm
	@echo "$(GREEN)fdf compiled$(DEF_COLOR)"
	
$(BUILD_DIR)/src/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/src/app/%.o: $(APP_DIR)/%.c
	@mkdir -p $(@D)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/src/common/%.o: $(COMMON_DIR)/%.c
	@mkdir -p $(@D)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@cd $(LIB_DIR)/libft -s && make -s

$(MINILIBX):
	@cd $(LIB_DIR) && $(MINILIBX_LIB)
	@cd $(LIB_DIR) && tar -xf minilibx-linux.tgz
	@rm $(LIB_DIR)/minilibx-linux.tgz
	@cd $(LIB_DIR)/minilibx-linux -s && make -s

clean:
	@$(RM) $(BUILD_DIR)
	@cd $(LIB_DIR)/libft && make clean
	@cd $(LIB_DIR)/minilibx-linux && make clean
	@echo "$(GRAY)files.o removed$(DEF_COLOR)"
	
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIB_DIR)/minilibx-linux
	@cd $(LIB_DIR)/libft && make fclean
	@echo "$(RED)fdf removed$(DEF_COLOR)"

re: fclean
	@make

.PHONY: all clean fclean re
