CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRC = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c\
			ft_isprint.c \
			ft_itoa.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_abs.c
OBJECT = $(SRC:.c=.o)
OBJECT_B = $(SRC_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	@ar -cr $@ $(OBJECT)

bonus : $(NAME) $(OBJECT_B)
	ar -cr $(NAME) $(OBJECT_B)

clean :
	@rm -f $(OBJECT) $(OBJECT_B)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.c.o :
	@$(CC) $(CFLAGS) -c -o $@ $<
