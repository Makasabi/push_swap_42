#################### INCLUDE ####################

-include make/includes.mk
-include make/sources.mk

INCPATH		:=	includes/
INC			:=	-I $(INCPATH)

################# FOLDER PATHS ##################

OBJFLDR		:=	.objects/

#################### SOURCES ####################

OBJS		:=	$(SOURCES:.c=.o)
OBJS		:=	$(addprefix $(OBJFLDR), $(OBJS))

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

MAKELIB		:=	ar -rcs

DEL			:=	rm -rf

NAME		:=	libft.a
NAMEEXEC	:=	prog

MAIN		:=  main_*

####################  RULES  ####################

${NAME}: ${OBJFLDR} ${OBJS} $(INCLUDES)
		${MAKELIB} ${NAME} ${OBJS}
		ranlib ${NAME}

all:	${NAME}

.objects/%.o:	%.c
		mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@ ${INC}

${OBJFLDR}:
		mkdir -p ${OBJFLDR}

clean:
		@if [ -d $(OBJFLDR) ];then $(DEL) $(OBJFLDR);fi

fclean: clean
		@if [ $(NAME) ];then ${DEL} ${NAME};fi
		@rm make/includes.mk make/sources.mk

re:		fclean all

gmk:
		@if [ -d make ];then echo ok;else mkdir make;fi
		@find -name '*.c' | sed 's/^/SOURCES += /' > make/sources.mk
		@find -name '*.h' | sed 's/^/INCLUDES += /' > make/includes.mk

test: $(NAME)
	$(CC) $(CFLAGS) -g $(MAIN) -o $(NAMEEXEC) -L . -lft


.PHONY: all clean fclean re%
