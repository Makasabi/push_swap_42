#################### INCLUDE ####################

INCPATH		:=	includes/
INC			= -I $(INCPATH)
INCBNS		= includes/checker.h 
INCLUDES	= includes/push_swap.h 
LIBFT		= libft/libft.a

################# SOURCES ##################

SRCFILES	= push_swap.c \
				args_stack_check.c \
				stack_building.c \
				rank_position.c \
				sort_min.c \
				sort_max.c \
				sort_max_lis.c \
				sort_max_chunks.c \
				sort_max_utils.c \
				sort_max_sort.c \
				op_swap.c \
				op_push.c \
				op_rotate.c \
				op_r_rotate.c \
				free_stack.c \
				printing.c \

SRCBNSFILES = checker_bonus.c \
				checks_bonus.c \
				free_stack_bonus.c \
				stack_building_bonus.c \
				execute_ops_bonus.c \
				op_swap_bonus.c \
				op_push_bonus.c \
				op_rotate_bonus.c \
				op_r_rotate_bonus.c \

SOURCES		= $(addprefix $(SRCFLDR), $(SRCFILES))
SOURCESBONUS = $(addprefix $(SRCBNSFLDR), $(SRCBNSFILES))

################# FOLDER PATHS ##################

OBJFLDR		=	.objects/
SRCFLDR		=	sources/
OBJBNSFLDR	=	.objects_bonus/
SRCBNSFLDR	=	sources_bonus/
LIBFTFLDR	=	libft/

#################### MACROS #####################

OBJS		= $(SOURCES:.c=.o)
OBJS		:= $(addprefix $(OBJFLDR), $(OBJS))
OBJS_BNS	= $(SOURCESBONUS:.c=.o)
OBJS_BNS	:= $(addprefix $(OBJBNSFLDR), $(OBJS_BNS))

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

LDFLAGS		= -L $(LIBFTFLDR) -lft

NAME		= push_swap
BONUS		= checker

#################### SOURCES ####################

$(NAME): $(OBJFLDR) $(OBJS) $(INCLUDES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

all: $(NAME)

.objects/%.o:	%.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@ ${INC}

.objects_bonus/%.o:	%.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@ ${INC}

${OBJFLDR}:
		@mkdir -p ${OBJFLDR}

${OBJBNSFLDR}:
		@mkdir -p ${OBJBNSFLDR}

$(LIBFT):
	@make gmk -C libft
	@make -C libft

bonus: $(OBJBNSFLDR) $(OBJS_BNS) $(INCBNS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BNS) -o $(BONUS) $(LDFLAGS)

clean:
	@if [ -d "$(OBJFLDR)" ]; then rm -rf $(OBJFLDR); fi
	@if [ -d "$(OBJBNSFLDR)" ]; then rm -rf $(OBJBNSFLDR); fi
	@make clean -C libft

fclean: clean
	@if [ "$(NAME)" ]; then rm -f $(NAME) ; fi
	@make fclean -C libft
	@if [ "$(BONUS) " ]; then rm -f $(BONUS) ; fi

re: 
	@make clean 
	@make all

.PHONY: all clean fclean re bonus%