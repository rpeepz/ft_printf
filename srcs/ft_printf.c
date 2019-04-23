/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:34:52 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/22 13:55:02 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Produces output according to a format string passed into funtion.
**	parses and converts variables to output based on conversion symbols
**	as standard logic for basic printf.
*/

int				parse_string(char **str, va_list ap)
{
	int		i;
	t_mods	modifier;

	(*str)++;
	if (**str)
		modifier = get_mods(str, ap);
	if (!(i = get_type_specifier(**str)))
	{
		if (**str)
			(*str)++;
		return (0);
	}
	IF_RETURN(i == 1 && (*str)++, convert_percent(modifier));
	IF_RETURN(i == 2 && (*str)++, convert_d(modifier, ap));
	IF_RETURN(i == 3 && (*str)++, convert_c(modifier, ap));
	IF_RETURN(i == 4 && (*str)++, convert_s(modifier, ap));
//	IF_RETURN(i == 5 && (*str)++, convert_p(modifier, ap));
//	IF_RETURN(i == 6 && (*str)++, convert_o(modifier, ap));
//	IF_RETURN(i == 7 && (*str)++, convert_u(modifier, ap));
//	IF_RETURN(i == 8 && (*str)++, convert_x(modifier, ap));
//	IF_RETURN(i == 9 && (*str)++, convert_f(modifier, ap));
//	IF_RETURN(i == 10 && (*str)++, convert_k(modifier, ap));
//	IF_RETURN(i == 11 && (*str)++, convert_help(modifier, ap));
	return (42);
}

int				ft_printf(char *str, ...)
{
	int		nbyte;
	va_list	ap;

	nbyte = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			print_one(&str);
			nbyte++;
		}
		else
		{
			nbyte += parse_string(&str, ap);
		}
	}
	va_end(ap);
	IF_THEN(nbyte < 0, nbyte = 0);
	return (nbyte);
}
