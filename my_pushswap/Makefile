M_NAME	= push_swap
M_SRCS	= 	arg_2_check.c\
			arg_check.c\
			ft_split.c\
			ft_strdup.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strtrim.c\
			judge_cmd.c\
			judge_sort_case.c\
			list.c\
			sort.c\
			stack_p.c\
			stack_s.c\
			stack_r.c\
			stack_rr.c\
			util.c\
			sub_sort.c\
			sort_util.c\
			sub_sort_terminal.c\
			ft_printf.c\
			ft_print_1.c\
			ft_print_2.c\
			push_swap.c
M_OBJS	= $(M_SRCS:.c=.o)
B_NAME	= checker
B_SRCS	= 	arg_2_check_bonus.c\
			arg_check_bonus.c\
			ft_split_bonus.c\
			ft_strdup_bonus.c\
			ft_strlcpy_bonus.c\
			ft_strlen_bonus.c\
			ft_strtrim_bonus.c\
			judge_cmd_bonus.c\
			list_bonus.c\
			stack_p_bonus.c\
			stack_s_bonus.c\
			stack_r_bonus.c\
			stack_rr_bonus.c\
			util_bonus.c\
			ft_printf_bonus.c\
			ft_print_1_bonus.c\
			ft_print_2_bonus.c\
			get_next_line.c\
			get_next_line_utils.c\
			checker.c
B_OBJS = $(B_SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# ifeq ($(MAKECMDGOALS), bonus)
# 	OBJS += $(B_OBJS);
# else
# 	OBJS += $(RM_B_OBJS);
# endif

$(M_NAME): $(M_OBJS)
	$(CC) $(CFLAGS) -o $(M_NAME) $(M_OBJS)

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJS)

all: $(M_NAME)

clean:
	rm -f $(M_OBJS) $(B_OBJS)

fclean: clean
	rm -f $(M_NAME) $(B_NAME)

re: fclean all

bonus: $(B_NAME)

.PHONY: all clean fclean re bonus
