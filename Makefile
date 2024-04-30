NAME = pipex
LIB = libft
FILES = main/main.c \
	main/free_array.c \
	main/perror_exit.c \
	main/fill_input.c \
	main/open_files.c \
	main/pipex.c \
	main/exec_cmd.c \
	main/child_process.c \
	main/get_path.c \
	main/get_cmd_path.c
FILES_BONUS = bonus/main.c \
	bonus/free_array.c \
	bonus/perror_exit.c \
	bonus/fill_input.c \
	bonus/open_files.c \
	bonus/pipex.c \
	bonus/exec_cmd.c \
	bonus/child_process.c \
	bonus/get_path.c \
	bonus/get_cmd_path.c
FLAGS = -Wall -Wextra -Werror

$(NAME): $(LIB)/$(LIB).a
	cc $(FLAGS) -o $@ $(FILES) $^
all: $(NAME)

clean:
	rm -f *.out
fclean: clean
	rm -f $(NAME) $(NAME)_bonus
re: fclean all

$(LIB)/$(LIB).a:
	make -C $(LIB)

bonus: $(NAME)_bonus

$(NAME)_bonus: $(LIB)/$(LIB).a
	cc $(FLAGS) -o $(NAME)_bonus $(FILES_BONUS) $^
