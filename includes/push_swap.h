/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:58 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/03/26 12:03:22 by pmelo-ca         ###   ########.fr       */
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
int					check_stack_is_sorted(t_stack *stack_a);
void				new_tree(int argc, int *stack_a, t_btree **btree);
void				insert_tree_node(t_btree **btree, int value, int counter, int argc);
void				insert_stack_nodes(t_stack **stack_a, t_btree *btree, int *arr_int);
void				push_top(t_stack **stack, int index, int pos, int value);
void				inorder_transversal(t_btree **btree, int *index);
void				init_stacks(t_stack **stack_a, t_stack **stack_b, t_btree **btree, int *arr_int);
int					search_index(int value, t_btree *btree);
void				clean_tree(t_btree *btree);
void				algorithm(t_stack **stack_a, t_stack **stack_b);
void 				sort_3(t_stack **stack_a);
void				sort_greater_than_3(t_stack **stack_a, t_stack **stack_b);
#endif
