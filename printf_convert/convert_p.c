/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:20:04 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/30 21:11:36 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	p		The void * pointer argument is printed in hexadecimal
**			(as if by `%#x' or `%#lx').
**			The effect of padding the %p format with zeros (either by the 0 flag
**			or by specifying a precision), and the benign effect (i.e., none) of
**			the # flag on %n and %p conversions, as well as other nonsensical
**			combinations are not standard; such combinations should be avoided.
*/

static int	right_justify(t_mods mod, char *str, int len, int nbyte)
{
	return (nbyte);
}

static int	left_justify(t_mods mod, char *str, int len, int nbyte)
{
	return (nbyte);
}

int			convert_p(t_mods modifiers, va_list ap)
{
	intptr_t	input;
	char		*tmp;
	char		*addr;
	int			nbyte;

	input = va_arg(ap, intptr_t);
	if (input)
	{
		tmp = num_string_u_base(input, 16);
		nbyte = -1;
		while (tmp[++nbyte])
			ft_tolower(tmp[nbyte]);
		addr = strjoin("0x", tmp);
		free(tmp);
	}
	else
		addr = ft_strdup("0x0");
	if (modifiers.flags.minus == 1)
		nbyte = left_justify(modifiers, addr, (int)ft_strlen(addr), 0);
	else
		nbyte = right_justify(modifiers, addr, (int)ft_strlen(addr), 0);
	free(addr);
	return (nbyte);
}
