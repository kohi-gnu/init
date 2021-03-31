CC	?= clang
RM	= rm -f

CFLAGS	+= -ansi -pedantic -Werror -Wall -Wextra
LDFLAGS	+=

SRCS	= main.c
OBJS	= $(addprefix src/, $(SRCS:.c=.o))

TARGET	= init

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
