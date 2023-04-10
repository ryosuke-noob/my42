/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:27:58 by nutar             #+#    #+#             */
/*   Updated: 2023/04/10 17:32:12 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# ifndef FALSE
#  define FALSE 0
# endif
# ifndef TURE
#  define TRUE 1
# endif

typedef struct s_integers
{
	int	*array;
	int	argc;
}	t_integers;

typedef struct s_list
{
	int				content;
	int				number;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;
	int		size_b;
	int		flag;
}	t_stack;

//my_check
void		check_stack(t_stack *stack);

//arg_check
t_integers	arg_check_all(int argc, char **argv);
//arg_2_check
t_integers	arg_2_check_all(int argc, char **argv);
//util
void		error_func(int	*array);
int			ft_isdigit(int c);
int			ft_atoi_edit(const char *str, int *array);
int			check_r_rr(t_stack stack, int max, int min);
//ft_split
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *src);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *c);
//list
void		my_lstadd_back(t_list **lst, t_list *new);
void		my_lstclear(t_list **lst);
t_list		*my_lstnew(int content, int number);
t_stack		create_stack(t_integers	integers);

//command
void		sa(t_stack *stack, int flag);
void		sb(t_stack *stack, int flag);
void		ss(t_stack *stack);
void		ra(t_stack *stack, int flag);
void		rb(t_stack *stack, int flag);
void		rr(t_stack *stack);
void		rra(t_stack *stack, int flag);
void		rrb(t_stack *stack, int flag);
void		rrr(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);

//judge
int			judge(t_stack stack, int flag);

//sort
void		sort(t_stack *stack);
void		judge_s(t_stack *stack);
void		judge_r(t_stack *stack);
void		judge_rr(t_stack *stack);
void		judge_s_size_5(t_stack *stack);
int			judge_2_1(t_list *tmp, int min);
int			judge_3_1(t_list *tmp, int min);

//sub_sort
void		sub_sort(t_stack *stack, int size, int max, int min);
// void		top_sort(t_stack *stack, int *size, int *max, int *min);
void		bottom_sort(t_stack *stack, int *size, int *max, int *min);
int			count_last_max(t_stack *stack, int size, int max);
int			count_min(t_stack *stack, int size, int min, int count);
int			sub_sort_terminal(t_stack *stack, int max, int min, int count);
int			count_min_a(t_stack *stack, int size, int min, int count);

#endif