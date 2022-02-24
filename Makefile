SRC =	main.c \
		cd.c \
		echo.c \
		env.c \
		exit.c \
		export.c \
		fill_env.c \
		fill_inf.c \
		pwd.c \
		unset.c \
		lib.c \
		lst.c \
		quote.c \
		split.c \
		ft_split.c \
		strtok.c \
		utils.c \
		choose.c \
		cmd.c

OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,${SRC})
OBJ_DIR	= objs/
LIBFT_DIR = libft/
BUILT_DIR = built/
PARS_DIR = parsing/
CMD_DIR = cmd/
INCLUDES_DIR = includes/

VPATH	= $(LIBFT_DIR) $(BUILT_DIR) $(PARS_DIR) $(CMD_DIR)

FLAGS = -Wall -Wextra -Werror -g
 
READ_FLAGS = -lreadline

$(OBJ_DIR)%.o	: %.c
				mkdir -p $(OBJ_DIR)
				cc $(FLAGS) -c $< -I$(INCLUDES_DIR) -o $@

NAME = mini

$(NAME): $(OBJ)
	cc $(FLAGS) -o $(NAME) $(OBJ) $(READ_FLAGS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
