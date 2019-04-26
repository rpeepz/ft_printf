/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:58:07 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/26 14:32:51 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	d, i	The int (or variant) argument is converted to signed decimal.
**			The precision, if any, gives the minimum number of digits
**			that must appear; if the converted value requires fewer digits,
**			it is padded on the left with zeros.
*/

static int		pad_width(t_mods mod, int len, int nbyte, int neg)
{
	char	*pad_char;

	pad_char = " ";
	if (len > mod.prcsn || mod.prcsn == -1)
	{
		if (mod.width > len)
		{
			IF_THEN(mod.flags.fzero && mod.prcsn == -1, pad_char = "0");
			if (nbyte == 0)
				while (mod.width - len - neg > nbyte)
					nbyte += (int)write(1, pad_char, 1);
			else
				while (mod.width - len > nbyte)
					nbyte += (int)write(1, pad_char, 1);
		}
	}
	else
	{
		while (mod.width - mod.prcsn - neg > nbyte)
			nbyte += (int)write(1, pad_char, 1);
	}
	return (nbyte);
}

static	int		right_justify(t_mods mod, char *num, int nbyte, int neg)
{
	if (neg == 1)
	{
		if (mod.flags.fzero && mod.prcsn < 0 && mod.width > (int)ft_strlen(num))
			nbyte += (int)write(1, "-", 1);
		nbyte = pad_width(mod, (int)ft_strlen(num), nbyte, neg);
		if (!mod.flags.fzero || mod.prcsn > 0 || !nbyte)
			nbyte += (int)write(1, "-", 1);
	}
	else if (neg == 0)
	{
		if (mod.flags.fplus && mod.flags.fzero && mod.prcsn < 0 &&
			mod.width > (int)ft_strlen(num) && (mod.flags.space = -1))
			nbyte += (int)write(1, "+", 1);
		nbyte = pad_width(mod, (int)ft_strlen(num), nbyte, mod.flags.fplus);
		if ((mod.flags.fplus && mod.flags.space != -1))
			nbyte += (int)write(1, "+", 1);
		if (!mod.flags.fplus && mod.flags.space && !nbyte)
			nbyte += (int)write(1, " ", 1);
	}
	if (mod.prcsn > (int)ft_strlen(num))
		while ((mod.prcsn--) - (int)ft_strlen(num) > 0)
			nbyte += (int)write(1, "0", 1);
	return (nbyte += (int)write(1, num, ft_strlen(num)));
}

static	int		left_justify(t_mods mod, char *num, int nbyte, int neg)
{
	int		len;

	len = (int)ft_strlen(num);
	if (neg == 1)
		nbyte += (int)write(1, "-", 1);
	else if (neg == 0)
	{
		if (mod.flags.fplus)
			nbyte += (int)write(1, "+", 1);
		else if (mod.flags.space)
			nbyte += (int)write(1, " ", 1);
	}
	while (mod.prcsn-- > len)
		nbyte += (int)write(1, "0", 1);
	nbyte += (int)write(1, num, len);
	while (nbyte < mod.width)
		nbyte += (int)write(1, " ", 1);
	return (nbyte);
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
	else if (length / 2 == 'l' || length == 'z')
		d = va_arg(ap, long long);
	else
		d = va_arg(ap, int);
	return (d);
}

int				convert_i(t_mods modifiers, va_list ap)
{
	int64_t	num;
	int		nbyte;
	int		neg;
	char	*str;

	nbyte = 0;
	num = convert_length(modifiers.length, ap);
	neg = (num < 0) ? 1 : 0;
	IF_THEN(neg == 1, num *= -1);
	str = num_string(num);
	IF_THEN(str[0] == '0' && modifiers.prcsn == 0, str[0] = '\0');
	if (modifiers.flags.minus == 1)
		nbyte += left_justify(modifiers, str, nbyte, neg);
	else
		nbyte += right_justify(modifiers, str, nbyte, neg);
	IF_RETURN(1, (ft_pipewrench("-s", str) + nbyte) - 1);
}
