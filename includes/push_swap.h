/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:58 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/27 20:30:56 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include <stdbool.h>
# include "../lib/gnl/get_next_line.h"
# include "../lib/libft.h"
# include "../lib/printf/ft_printf.h"

typedef struct s_btree
{
	int				value;
	int				index;
	int				pos;
	struct s_btree	*right;
	struct s_btree	*left;
}					t_btree;

typedef struct s_node
{
	int				index;
	int				pos_a;
	int 			pos_b;
	int				target_pos;
	int				cost;
}					t_node;

typedef struct s_stack
{
	struct s_node	*curr;
	struct s_node	*next;
	struct s_node	*prev;
}					t_stack;

t_btree				*validate_arg(int argc, char **argv);
int					*get_int_argc(int argc, char **argv);
t_btree				*new_tree(int argc, int *stack_a);
t_btree				*insert_node(t_btree *head, int value, int counter);
void				get_pos(t_btree *btree);
void				init_stacks(t_stack *stack_a, t_stack *stack_b, t_btree *btree);
void				clean_tree(t_btree *btree);
#endif
