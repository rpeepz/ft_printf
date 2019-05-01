/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:11:29 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/26 12:46:45 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** OBSOLETE VERSION
*/

static	int		left_justify(t_mods mod, char *num, int len, int nbyte)
{
	if (*num != '-')
	{
		if (mod.flags.fplus)
			nbyte += (int)write(1, "+", 1);
		else if (mod.flags.space)
			nbyte += (int)write(1, " ", 1);
	}
	else if (*num == '-')
	{
		nbyte += (int)write(1, "-", 1);
		len--;
		num++;
	}
	while (mod.prcsn-- > len)
		nbyte += (int)write(1, "0", 1);
	nbyte += (int)write(1, num, len);
	while (nbyte < mod.width)
		nbyte += (int)write(1, " ", 1);
	return (nbyte);
}

static int		pad_width(t_mods mod, int len, int nbyte, char *num)
{
	char *pad_char;

	pad_char = " ";
	if (len > mod.prcsn || mod.prcsn == -1)
	{
		if (mod.width > len)
		{
			if (mod.flags.fzero)
				pad_char = "0";
			while (mod.width - len > nbyte)
				nbyte += (int)write(1, pad_char, 1);
		}
	}
	else
	{
		if (mod.flags.fzero && !nbyte && *num == '-')
			mod.width -= 1;
		while (mod.width - mod.prcsn > nbyte)
			nbyte += (int)write(1, pad_char, 1);
	}
	return (nbyte);
}

static int		right_justify(t_mods mod, char *num, int len, int nbyte)
{
	if (*num == '-')
	{
		if (mod.flags.fzero && mod.width > len && mod.prcsn == -1)
			IF_THEN(nbyte += (int)write(1, num++, 1), len--);
		nbyte = pad_width(mod, len, nbyte, num);
		IF_THEN(*num == '-' && (nbyte += (int)write(1, num++, 1)), len--);
	}
	else
	{
		IF_THEN(mod.flags.fplus && !mod.flags.fzero, mod.width -= 1);
		if (mod.flags.fplus && mod.flags.fzero)
			nbyte += (int)write(1, "+", 1);
		nbyte = pad_width(mod, len, nbyte, num);
		if (!mod.flags.fplus && mod.flags.space && !nbyte)
			nbyte += (int)write(1, " ", 1);
		if (mod.flags.fplus && !mod.flags.fzero)
			IF_THEN(nbyte += (int)write(1, "+", 1), mod.width += 1);
	}
	if (mod.flags.fzero && mod.prcsn < len)
		while (mod.width - len > nbyte)
			nbyte += (int)write(1, "0", 1);
	if (mod.prcsn > len)
		while ((mod.prcsn--) - len > 0)
			nbyte += (int)write(1, "0", 1);
	IF_RETURN(1, nbyte += (int)write(1, num, len));
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

int				convert_d(t_mods modifiers, va_list ap)
{
	int64_t	num;
	int		nbyte;
	char	*str;

	nbyte = 0;
	num = convert_length(modifiers.length, ap);
	str = ft_itoa(num);
	IF_THEN(str[0] == '0' && modifiers.prcsn == 0, str[0] = '\0');
	if (modifiers.flags.minus == 1)
		nbyte += left_justify(modifiers, str, (int)ft_strlen(str), 0);
	else
		nbyte += right_justify(modifiers, str, (int)ft_strlen(str), 0);
	IF_RETURN(1, (ft_pipewrench("-s", str) + nbyte) - 1);
}
