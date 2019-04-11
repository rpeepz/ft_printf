/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:52:45 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/10 20:14:52 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		left_justify(int width, unsigned char c)
{
	int		n;

	n = (int)write(1, &c, 1);
	if (n < width)
		while (n < width)
			n += (int)write(1, " ", 1);
	return (n);
}

static int		right_justify(int width, int fzero, unsigned char c)
{
	int		n;
	int		i;

	i = width;
	if (fzero)
	{
		while (i-- > 1)
			n = (int)write(1, "0", 1);
	}
	else
	{
		while (i-- > 1)
			n = (int)write(1, " ", 1);
	}
	n += (int)write(1, &c, 1);
	return (n);
}
/*
**	c	The int argument is converted to an unsigned char,
**		and the resulting character is written.
*/

int				convert_c(t_mods modifiers, va_list ap)
{
	unsigned char	c;

	c = va_arg(ap, int);
	if (modifiers.flags.minus == 1)
	{
		return (left_justify(modifiers.width, c));
	}
	if (modifiers.width > 1)
	{
		return (right_justify(modifiers.width, modifiers.flags.fzero, c));
	}
	return ((int)write(1, &c, 1));
}
