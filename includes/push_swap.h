/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:58 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/01 23:46:20 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../lib/gnl/get_next_line.h"
# include "../lib/libft.h"
# include "../lib/printf/ft_printf.h"

typedef struct s_btree
{
	struct s_btree	*right;
	struct s_btree	*left;
	int				value;
	int				index;
	short int		amount_of_numbers;
}					t_btree;

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
	int				index;
	int				pos_a;
	int 			pos_b;
	int				target_pos;
	int				cost_move;
}					t_node;

typedef struct s_stack
{
	struct s_node	*top;
	int				amount_of_numbers;
}					t_stack;

void				validate_arg(int argc, char **argv, int **arr_int);
int					exit_status(int error, char *message);
void				get_int_argc(int argc, char **argv, int **arr_int);
void				new_tree(int argc, int *stack_a, t_btree **btree);
void				insert_tree_node(t_btree **btree, int value, int counter, int argc);
void				insert_stack_nodes(t_stack **stack_a, t_btree *btree, int *arr_int);
void				push_top(t_stack **stack, int index, int pos, int value);
void				inorder_transversal(t_btree **btree, int *index);
void				init_stacks(t_stack **stack_a, t_stack **stack_b, t_btree **btree, int *arr_int);
int					search_index(int value, t_btree *btree);
void				clean_tree(t_btree *btree);
int					check_stack_is_sorted(t_stack *stack_a);
void				algorithm(t_stack **stack_a, t_stack **stack_b);
void 				sort_3(t_stack **stack_a);
void				sort_greater_than_3(t_stack **stack_a, t_stack **stack_b);
void				push_b_until_three (t_stack **stack_a, t_stack **stack_b);
void				push(t_stack **stack_source, t_stack **stack_dest, char *message);
void				swap(t_stack **stack_source, char *message);
void				rotate(t_stack **stack_source, char *message);
void				reverse_rotate(t_stack **stack_source, char *message);
t_node 				*dup_node(t_node *node_source);
void				update_position(t_stack *stack_a, t_stack* stack_b);
void				calc_target_pos(t_stack *stack_a, t_stack *stack_b);
void				get_move_cost(t_stack *stack_a, t_stack *stack_b);
void				make_cheapest(t_stack **stack_a, t_stack **stack_b);
void				validate_rotates(t_stack **stack_a);
void 				execute_moves(t_stack **stack_a, t_stack **stack_b, int lower_cost_pos, int lower_cost);
int					get_stack_size(t_stack *stack_source);
#endif
