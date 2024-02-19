/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:58 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/19 14:24:08 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../lib/gnl/get_next_line.h"
# include "../lib/libft.h"
# include "../lib/printf/ft_printf.h"

typedef struct s_btree
{
	int				value;
	int				curr_index;
	int				beg_index;
	int				req_index;
	struct s_btree	*right;
	struct s_btree	*left;
}					t_btree;

typedef struct s_push_swap
{
	struct s_btree	*btree;
	int				*stack_a;
	int				*stack_b;
}					t_push_swap;

t_btree				*validate_arg(int argc, char **argv);
int					*get_int_argc(int argc, char **argv);
t_btree				*new_tree(int argc, int *stack_a);
t_btree				*insert_node(t_btree *head, int value, int counter);
void				clean_tree(t_btree *btree);
#endif
