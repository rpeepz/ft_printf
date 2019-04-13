/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:11:29 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/12 19:45:02 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		right_justify(t_mods mods, char *num, int len, int nbyte)
{
	if (mods.flags.space && !mods.flags.fplus)
		nbyte += (int)write(1, " ", 1);
	if (mods.flags.fplus && num[0] != '-')
		nbyte += (int)write(1, "+", 1);
	if (mods.precision > 0 && mods.precision > len)
	{
		while (mods.precision >= len && *num != '-')
			nbyte += (int)write(1, "0", mods.precision--);
		if (*num == '-')
		{
			nbyte += (int)write(1, '-', 1);
			num++;
			while (mods.precision >= len)
				nbyte += (int)write(1, "0", mods.precision--);
			return (nbyte += (int)write(1, num, len - 1));
		}
		return (nbyte += (int)write(1, num, len));
	}
	else if (mods.precision == 0)
	{
		if (mods.flags.fzero)
			pad_left_zero();
		else
			pad_right_zero();
	}
}

static int64_t	get_lengthmod(int length, va_list ap)
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

int				convert_d(t_mods mods, va_list ap)
{
	int		d;
	int		nbyte;
	char	*num;

	d = get_lengthmod(mods.length, ap);
	num = ft_itoa(d);
	d = (int)ft_strlen(num);
	nbyte = 0;
	IF_THEN(mods.precision < 0, mods.precision == 0);
	if (mods.width <= (d + mods.precision))
	{
		if (mods.flags.minus == 0)
			nbyte += right_justify(mods, num, d, 0);
		else
			nbyte += left_justify(mods, num, d, 0);
	}
	else
	{
		if (mods.flags.minus == 0)
			nbyte += right_justifybig(mods, num, d, 0);
		else
			nbyte += left_justifybig(mods, num, d, 0);
	}
	free(num);
	return (nbyte);
}
