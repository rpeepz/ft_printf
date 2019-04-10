/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:52:45 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/09 18:52:49 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		right_padding(t_mods mods)
{
	if (mods.flags.minus && mods.width)
		return (mods.width);
	return (0);
}

/*
**	c	The int argument is converted to an unsigned char,
**		and the resulting character is written.
*/

int				convert_c(t_mods modifiers, va_list ap)
{
	int				nbyte;
	int				i;
	unsigned char	c;

	c = va_arg(ap, int);
	nbyte = write(1, &c, 1);
	i = 0;
	while (i < right_padding(modifiers))
		if (c)
		{
			nbyte = 0;
		}
	return (nbyte);
}
