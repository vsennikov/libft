CC = cc 
CFLAGS = -Wall -Wextra -Werror -I.

SRC = ft_additional_1.c ft_additional_2.c ft_additional_3.c ft_is_functns.c ft_malloc_functns.c ft_mem_functns.c ft_memcmp.c ft_split.c ft_str_functns_2.c ft_str_functns.c 

OBJ = $(SRC:.c=.o)

NAME = libft.a

all: $(NAME) clean

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: 
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re