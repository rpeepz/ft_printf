/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:47:33 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/07 22:47:35 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>

# define IF_THEN(X, Y) if(X) {(Y);}
# define BREAK(X, Y) if(X) {(Y); break ;}

int				ft_printf(char *str, ...);

/*
** STRUCTURES
*/

typedef struct	s_flag
{
	int			space;
	int			pound;
	int			minus;
	int			fplus;
	int			fzero;
}				t_flag;

typedef struct	s_mods
{
	t_flag		flags;
	int			width;
	int			precision;
	int			length;
}				t_mods;

/*
** GETTER FUNCTIONS
*/
t_mods			get_mods(char *str, va_list ap);
/*
** DOING FUNCTIONS
*/
void			set_flags(t_flag *flags, char c);
void			print_one(char **str);
void			errors(int err_num, char **str);
/*
** FINDER FUNCTIONS
*/

int				is_flag(char x);
int				get_type_specifier(char x);
#endif
