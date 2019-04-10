/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_things.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:46:20 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/08 20:46:21 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_one(char **str)
{
	ft_putchar(**str);
	(*str)++;
}

void		errors(int err_num, char **str)
{
	if (err_num == 1)
		ft_printf("\"%c <-invalid specifier\"", *(*str - 1));
}

void		set_flags(t_flag *flags, char c)
{
	if (c == ' ')
		flags->space = 1;
	else if (c == '#')
		flags->pound = 1;
	else if (c == '+')
		flags->fplus = 1;
	else if (c == '-')
		flags->minus = 1;
	else if (c == '0')
		flags->fzero = 1;
}
/*
**	FLAGS
**	' '		(f, F, d i)
**space gives just one blank before output. can be overwritten by plus.
**(c)	no effect
**	'+'		(d, i, f, F)
**plus forces plus or minus sign before output of signed conversions.
**(c)	no effect
**	'0'		(all)
**zero turns padding from blanks to zeros. if a precision is present
**with the numeric conversion (d, i, o, u, x, X) the zero is ignored.
**(c)	no effect
**	'-'		(all)
**minus will set left alignment with padding to the right only by blanks
**specified ammount in width. overrides the zero flag.
**	'#'		(f, F, (e, E, g, G))
**pound forces result to include decimal point.
**	(o, x, X)outputs 0, 0x, 0X respectively to beginning of non zero numbers
**	(g, G)trailing zeros are not removed
**(c)	no effect
**	WIDTH	(all)
**controls min number of chars to print. if value is shorter result will
**be padded with ' ' on left (or right if '-'). value is not truncated
**can be combined with '0' flag.
**	PRECISION	(d, i, o, u , x, X)
**controls min number of digits to print. if no digit string assumed 0
**if value is shorter result will be padded with '0' on left.
**value is not truncated
**	(f, F, (a, A, e, E)min number of digits to appear after decimal
**	(g, G)max number of significant digits
**	(s)max num of chars to print.
**(c) no effect
**	LENGTH
**calls for specific "length" variable conversion
**		d, i			o, u, x, X
**	hh	signed char		unsigned char
**	h	short			unsigned short
**	l	long			unsigned long
**	ll	long long		unsigned long long
**		f, F, (e, E, g, G)	c		s
**	l 	double				wint_t	wchar_t*
**	L	long double
**if its not mentioned its undefined and therefore omitted
*/
