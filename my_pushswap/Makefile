NAME	= push_swap
SRCS	= 	arg_2_check.c\
			arg_check.c\
			ft_split.c\
			ft_strdup.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strtrim.c\
			judge_cmd.c\
			judge_sort_case.c\
			list.c\
			push_swap.c\
			sort.c\
			stack_p.c\
			stack_s.c\
			stack_r.c\
			stack_rr.c\
			util.c\
			sub_sort.c\
			sort_util.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

ifeq ($(MAKECMDGOALS), bonus)
OBJS += $(B_OBJS);
endif

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
