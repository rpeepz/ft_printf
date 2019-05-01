/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:04:29 by rpapagna          #+#    #+#             */
/*   Updated: 2019/05/01 00:09:02 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**  f, F    The double argument is rounded and converted to decimal notation in
**          the style [-]ddd.ddd, where the number of digits after the
**          decimal-point character is equal to the precision specification.
**          If the precision is missing, it is taken as 6; if the precision is
**          explicitly zero, no decimal-point character appears.
**          If a decimal point appears, at least one digit appears before it.
*/

static int			right_justify(t_mods mod, char **str, int nbyte, int len)
{
	return (nbyte);
}

static int			left_justify(t_mods mod, char **str, int nbyte, int len)
{
	return (nbyte);
}

int					convert_f(t_mods modifiers, va_list ap, int i)
{
	long double		num;
	char			**str;
	int				nbyte;

	if (modifiers.length)
	{
		if (modifiers.length == 'L' || i == 19)
			num = va_arg(ap, long double);
		else if (modifiers.length == 'l' || modifiers.length / 2 == 'l')
			num = va_arg(ap, double);
	}
	else
		num = va_arg(ap, float);
	str = num_string_modld(num, modifiers);
	if (modifiers.flags.minus == 1)
		nbyte = left_justify(modifiers, str, nbyte,
		(ft_strlen(str[0]) + ft_strlen(str[1]) + 1));
	else
		nbyte = right_justify(modifiers, str, nbyte,
		(ft_strlen(str[0]) + ft_strlen(str[1]) + 1));
	ft_pipewrench("--s", str);
	return (nbyte);
}
