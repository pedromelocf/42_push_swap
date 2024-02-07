/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:58 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/07 14:58:41 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../lib/gnl/get_next_line.h"
# include "../lib/libft.h"
# include "../lib/printf/ft_printf.h"

typedef struct s_list
{
	struct s_list	*next;
	int				value;
}					t_list;

t_list				*validate_arg(int argc, char **argv);
t_list				*new_list(int argc, char **argv);
#endif
