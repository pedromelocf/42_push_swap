#LIBFT
LIBFT_DIR = ./libraries
LIBFT_PATH = ./libraries/libft/*.o ./libraries/libft/*.a
LIB_PATH = ./libraries/*.a
GNL_OBJ = ./libraries/gnl/*.o
PRINTF_OBJ = ./libraries/printf/*.o

#PUSH_SWAP
NAME = push_swap
PUSH_SWAP_SRC_PATH = ./push_swap_utils/
PUSH_SWAP_INCLUDES = ./includes/push_swap.h
PUSH_SWAP_OBJ = $(addprefix $(PUSH_SWAP_SRC_PATH), $(PUSH_SWAP_SRCS:.c=.o))

PUSH_SWAP_SRCS = main.c \
	validations.c \
	btree_utils.c \
	stacks_utils.c \
	exit_status.c \
	algorithm.c \
	operations.c \
	algorithms_utils.c \
	make_movements.c

#FLAGS
FLAGS = -Wall -Werror -Wextra
CC = cc -g3
MAKEFLAG += make --no-print-directory

#MESSAGES
MESSAGE1 = "----------------Compiling Push Swap Objects!-----------------"
MESSAGE2 = "---------------Objects Compiled Successfully!----------------"
MESSAGE3 = "--------------./push_swap Compiled Successfully!-------------"
MESSAGE4 = "-------------------- All Objects cleaned!--------------------"
MESSAGE5 = "-------------------- All Binaries cleaned!-------------------"
MESSAGE6 = "-----------------Copying libfprintf.a Binarie----------------"

all: libft $(NAME)

$(NAME): $(PUSH_SWAP_OBJ)
	@ echo $(MESSAGE6)
	@ echo ' '
	@ echo $(MESSAGE1)
	@ $(CC) $(FLAGS) $(PUSH_SWAP_OBJ) $(LIB_PATH) -o $(NAME)
	@ echo ' '
	@echo $(MESSAGE2)
	@ echo ' '
	@ echo $(MESSAGE3)
	@ echo ' '
	@ echo ' '

$(PUSH_SWAP_SRC_PATH)%.o: $(PUSH_SWAP_SRC_PATH)%.c $(PUSH_SWAP_INCLUDES)
	@ $(CC) $(FLAGS) -c $< -o $@

clean :
	@ rm -f $(PUSH_SWAP_OBJ) $(LIBFT_PATH) $(LIB_PATH) $(GNL_OBJ) $(PRINTF_OBJ)
	@ echo ' '
	@ echo $(MESSAGE4)
	@ echo ' '

fclean : clean
	@ rm -f $(NAME)
	@ echo $(MESSAGE5)
	@ echo ' '
	@ echo ' '

re : fclean all

libft :
	@ $(MAKEFLAG) -C $(LIBFT_DIR)
	@ echo ' '

.PHONY: all clean fclean re libft
