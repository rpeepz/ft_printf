/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:11:29 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/15 22:34:53 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		left_justify(t_mods mod, char *num, int len, int nbyte)
{
	if (*num != '-')
	{
		if (mod.flags.fplus)
			nbyte += (int)write(1, "+", 1);
		else if (mod.flags.space && !mod.flags.fplus)
			nbyte += (int)write(1, " ", 1);
	}
	else if (*num == '-')
	{
		nbyte += (int)write(1, num++, 1);
		len--;
	}
	while (mod.precision - len > 0)
		nbyte += (int)write(1, "0", (mod.precision-- - len));
	nbyte += (int)write(1, num, len);
	while (mod.width > nbyte)
		nbyte += (int)write(1, " ", 1);
	return (nbyte);
}

static int		right_justify(t_mods mod, char *num, int len, int nbyte)
{
	if (*num == '-' && (len--))
	{
		IF_THEN(mod.flags.fplus == 1, mod.flags.fplus = 0);
		while (nbyte < mod.width - mod.precision - mod.flags.fplus - 1)
			nbyte += (int)write(1, " ", 1);
		nbyte += (int)write(1, "-", 1);
		num++;
	}
	else
	{
		if (!mod.flags.fplus && mod.flags.space)
			nbyte += (int)write(1, " ", 1);
		while (nbyte < mod.width - mod.precision)
			nbyte += (int)write(1, " ", 1);
		if (!nbyte)
		{
			while (nbyte < mod.width - mod.precision - mod.flags.fplus - 2)
				nbyte += (int)write(1, " ", 1);
			IF_THEN(mod.flags.fplus, nbyte += (int)write(1, "+", 1));
		}
	}
	while (mod.precision-- > len)
		nbyte += (int)write(1, "0", 1);
	return (nbyte += (int)write(1, num, len));
}

static int64_t	convert_length(int length, va_list ap)
{
	int64_t		d;

	if (length == 'h')
	{
		d = va_arg(ap, int);
		return ((short)d);
	}
	else if (length / 2 == 'h')
	{
		d = va_arg(ap, int);
		return ((signed char)d);
	}
	else if (length == 'l')
		d = va_arg(ap, long);
	else if (length / 2 == 'l')
		d = va_arg(ap, long long);
	else
		d = va_arg(ap, int);
	return (d);
}

/*
**	d, i	The int (or variant) argument is converted to signed decimal.
**			The precision, if any, gives the minimum number of digits
**			that must appear; if the converted value requires fewer digits,
**			it is padded on the left with zeros.
*/

int				convert_d(t_mods mod, va_list ap)
{
	int64_t	variable;
	int		len;
	int		nbyte;
	char	*num;

	variable = convert_length(mod.length, ap);
	num = ft_itoa(variable);
	len = (int)ft_strlen(num);
	nbyte = 0;
	IF_THEN(mod.precision < 0, mod.precision = 0);
	IF_THEN(mod.width < mod.precision || mod.width < len, mod.width = 0);
	if (mod.flags.minus == 1)
		nbyte += left_justify(mod, num, len, 0);
	else
		nbyte += right_justify(mod, num, len, 0);
	free(num);
	return (nbyte);
}
