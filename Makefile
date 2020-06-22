# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		dasm

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		sources
HDR_DIR	=		includes
OBJ_DIR	=		objs

# ------------  LIBFT  --------50--------------------------------------------- #
LFT		=		libft.a
LFT_DIR	=		libft
LHS_DIR	=		$(LFT_DIR)

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		main.c \
				tools.c \
				parse.c \
				init.c \
				code.c \
				free.c \
				parse_tools.c \
				extra_init.c
				

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
IFLGS	=		-I $(HDR_DIR) -I $(LHS_DIR)
LFLGS	=		-L $(LFT_DIR) -lft
DFLGS	=		-MMD -MP
DEBUG	=		-g

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

$(LFT_DIR)/$(LFT):
	@echo "\x1b[1m\nBuilding $(LIBFT) library...\x1b[0m"
	$(MAKE) -C $(LFT_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -g -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_DIR)/$(LFT) $(OBJS)
	@echo "\x1b[1m\nBuilding $(NAME)...\x1b[0m"
	$(CC) $(CFLGS) -g -o $(NAME) $(OBJS) $(LFLGS)

clean:
	@echo "\x1b[1m\nCleaning...\x1b[0m"
	$(MAKE) -C $(LFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
