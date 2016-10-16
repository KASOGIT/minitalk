CC=		gcc

RM=		rm -f

CFLAGS=		-I./include/ -O2 -pipe #-Wextra -Wall -Werror

NAME_CLIENT=	./client/client

NAME_SERVER=	./server/server

SRCS_CLIENT=	./client/client.c \

SRCS_SERVER=	./server/server.c \
		./server/server_misc.c \

OBJS_CLIENT=	$(SRCS_CLIENT:.c=.o)

OBJS_SERVER=	$(SRCS_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
		$(CC) $(OBJS_CLIENT) -o $(NAME_CLIENT) $(LDFLAGS) -L./lib/ -lmy

$(NAME_SERVER): $(OBJS_SERVER)
		$(CC) $(OBJS_SERVER) -o $(NAME_SERVER) $(LDFLAGS) -L./lib/ -lmy

clean:
	$(RM) $(OBJS_CLIENT)
	$(RM) $(OBJS_SERVER)

fclean:	clean
	$(RM) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER)

re: fclean all

.PHONY:	all fclean re
