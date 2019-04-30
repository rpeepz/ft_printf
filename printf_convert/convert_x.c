/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:07:17 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/30 02:03:30 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	x, X	The int (or variant) argument is converted to unsigned hexadecimal.
**			The precision, if any, gives the minimum number of digits
**			that must appear; if the converted value requires fewer digits,
**			it is padded on the left with zeros.
*/

static int		pad_width(t_mods mod, int len, int nbyte)
{
	char	*pad_char;

	pad_char = " ";
	if (len > mod.prcsn || mod.prcsn == -1)
	{
		if (mod.width > len)
		{
			IF_THEN(mod.flags.fzero && mod.prcsn == -1, pad_char = "0");
			if (nbyte == 0)
			{
				if (mod.flags.space && mod.flags.fzero)
					nbyte += write(1, " ", 1);
				while (mod.width - len > nbyte)
					nbyte += (int)write(1, pad_char, 1);
			}
			else
				while (mod.width - len > nbyte)
					nbyte += (int)write(1, pad_char, 1);
		}
	}
	else
		while (mod.width - mod.prcsn > nbyte)
			nbyte += (int)write(1, pad_char, 1);
	return (nbyte);
}

static	int		right_justify(t_mods mod, char *num, int nbyte, int capital)
{
	int		len;

	len = (int)ft_strlen(num);
	nbyte = pad_width(mod, len, nbyte);
	if (mod.prcsn > len)
		while ((mod.prcsn--) - len > 0)
			nbyte += (int)write(1, "0", 1);
	if (mod.flags.pound && num[0] != '0' && num[0] != '\0')
	{
		if (capital < 11)
			nbyte += (int)write(1, "0x", 2);
		else
			nbyte += (int)write(1, "0X", 2);
	}
	nbyte += (int)write(1, num, len);
	return (nbyte);
}

static	int		left_justify(t_mods mod, char *num, int nbyte, int capital)
{
	int		len;

	len = (int)ft_strlen(num);
	while (mod.prcsn-- > len)
		nbyte += (int)write(1, "0", 1);
	if (mod.flags.pound && num[0] != '0' && num[0] != '\0')
	{
		if (capital < 11)
			nbyte += (int)write(1, "0x", 2);
		else
			nbyte += (int)write(1, "0X", 2);
	}
	nbyte += (int)write(1, num, len);
	while (nbyte < mod.width)
		nbyte += (int)write(1, " ", 1);
	return (nbyte);
}

static uint64_t	convert_length(int length, va_list ap)
{
	uint64_t		x;

	if (length == 'h')
	{
		x = va_arg(ap, int);
		return ((unsigned short)x);
	}
	else if (length / 2 == 'h')
	{
		x = va_arg(ap, int);
		return ((unsigned char)x);
	}
	else if (length == 'l')
		x = va_arg(ap, unsigned long);
	else if (length / 2 == 'l' || length == 'z')
		x = va_arg(ap, unsigned long long);
	else
		x = va_arg(ap, int);
	return (x);
}

int				convert_x(t_mods modifiers, va_list ap, int i)
{
	uint64_t	num;
	int			nbyte;
	int			len;
	char		*str;

	nbyte = 0;
	len = -1;
	num = convert_length(modifiers.length, ap);
	if (modifiers.length == 'l' || modifiers.length / 2 == 'l' ||
		modifiers.length == 'z')
		str = num_string_u_base(num, 16);
	else
		str = ft_uitoa_base(num, 16);
	if (i < 11)
		while (str[++len])
			str[len] = ft_tolower(str[len]);
	IF_THEN(str[0] == '0' && modifiers.prcsn == 0, str[0] = '\0');
	if (modifiers.flags.minus == 1)
		nbyte += left_justify(modifiers, str, nbyte, i);
	else
		nbyte += right_justify(modifiers, str, nbyte, i);
	if (str)
		free(str);
	return (nbyte);
}
