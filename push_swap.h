#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"


typedef struct s_stack
{
    int         nbr;
    int         position;
    int         push_cost;
    bool        above_median;
    bool        cheapest; 
    struct s_stack  *prev;
    struct s_stack  *next;
    struct s_stack  *target_node;
} t_stack;

int main(int argc, char **argv);

/****initialize stack****/
void init_stack_a(t_stack **stack, char **argv, int split);

/***handle errors***/
void    free_stack(t_stack **stack);
int     check_dup(t_stack *a, int n);
void    free_error(t_stack **a, char **argv, int split);
int     check_syntax(char *a);

//sort 3
void	sort_three(t_stack **a);

/***stack utils***/
t_stack	*find_last(t_stack *stack);
int		stack_len(t_stack *stack);
bool	stack_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);

/****commands****/
//push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

//rev rotate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);


//swap function
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);

/****algorithm****/
void	bring_to_top(t_stack **stack, t_stack *cheapest_node, char stack_name);
//void		calc_cost(t_stack *a, t_stack *b);
void	current_pos(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
//void	min_to_top(t_stack **stack);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	push_cheapest(t_stack *stack);
void	prep_a_stack(t_stack *a, t_stack *b);
void	prep_b_stack(t_stack *a, t_stack *b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	sort_stacks(t_stack **a, t_stack **b);
void	target_node_a(t_stack *a, t_stack *b);
void	target_node_b(t_stack *a, t_stack *b);

/*for testing*/
void    print_stack(t_stack *stack);
//int	count_words(const char *s, char c);
void    ft_free_split(char **result);

# endif