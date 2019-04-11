/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:39:16 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/10 20:51:23 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		left_justify(int width)
{
	int		n;

	n = (int)write(1, "%", 1);
	if (n < width)
		while (n < width)
			n += (int)write(1, " ", 1);
	return (n);
}

static int		right_justify(int width, int fzero)
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
	n += (int)write(1, "%", 1);
	return (n);
}
/*
**	%	A `%' is written.  No argument is converted.
**		The complete conversion specification is `%%'.
*/

int				convert_percent(t_mods modifiers)
{
	if (modifiers.flags.minus == 1)
	{
		return (left_justify(modifiers.width));
	}
	if (modifiers.width > 1)
	{
		return (right_justify(modifiers.width, modifiers.flags.fzero));
	}
	return((int)write(1, "%", 1));
}
