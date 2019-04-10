/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mods.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:18:14 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/09 20:18:16 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_flag	get_flags(char **str)
{
	t_flag	flags;

	flags.space = 0;
	flags.pound = 0;
	flags.fplus = 0;
	flags.minus = 0;
	flags.fzero = 0;
	while (is_flag(**str))
	{
		set_flags(&flags, **str);
		(*str)++;
	}
	return (flags);
}

static int		get_width(char **str, va_list ap)
{
	int		width;

	width = 0;
	if (ft_isdigit(**str))
	{
		width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	else if (**str == '*')
	{
		width = va_arg(ap, int);
		(*str)++;
	}
	return (width);
}

static int		get_precision(char **str, va_list ap)
{
	int		precision;

	precision = -1;
	if (**str == '.')
	{
		precision = 0;
		(*str)++;
		if (ft_isdigit(**str))
		{
			precision = ft_atoi(*str);
			IF_THEN(precision < 0, precision = -1);
			while (ft_isdigit(**str))
				(*str)++;
		}
		else if (**str == '*')
		{
			precision = va_arg(ap, int);
			IF_THEN(precision < 0, precision = -1);
			(*str)++;
		}
	}
	if (precision >= 0)
		return (precision);
	return (-1);
}

static int		get_length(char **str)
{
	int		length;

	length = 0;
	if (**str == 'L')
		length = (int)'L';
	else if (**str == 'h' && *(*str + 1) != 'h')
		length = (int)'h';
	else if (**str == 'h' && *(*str + 1) == 'h')
		length = (int)('h' + 'h');
	else if (**str == 'l' && *(*str + 1) != 'l')
		length = (int)'l';
	else if (**str == 'l' && *(*str + 1) == 'l')
		length = (int)('l' + 'l');
	if (length > 0)
	{
		if (length >= 'h' + 'h')
			(*str) += 2;
		else
			(*str) += 1;
	}
	return (length);
}

t_mods			get_mods(char *str, va_list ap)
{
	t_mods modifiers;

	modifiers.flags = get_flags(&str);
	modifiers.width = get_width(&str, ap);
	modifiers.precision = get_precision(&str, ap);
	modifiers.length = get_length(&str);
	return (modifiers);
}
/*
**	the format for my getter functions were
**	inspired by the great work of my friend, Chris Bagdon
**	https://github.com/cbg119/42-ft_printf/blob/master/src/options.c
*/
