CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./includes -I./libft
NAME = pipex
LIBS = -L./libft -lft

SRC_DIR = ./srcs/
BONUS_DIR = ./bonus/

SRC_LIST = error.c\
get_next_line_utils.c\
get_next_line.c\
openfile.c\
pipex_utils.c\
pipex.c

BONUS_LIST = error_bonus.c\
get_next_line_utils_bonus.c\
get_next_line_bonus.c\
openfile_bonus.c\
pipex_utils_bonus.c\
pipex_bonus.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_LIST))
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_LIST))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft all
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) $(LIBS)
	
all : $(NAME)

bonus : $(BONUS_OBJS)
	$(MAKE) -C ./libft all
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(BONUS_OBJS) $(LIBS)

clean :
	$(MAKE) -C ./libft clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re