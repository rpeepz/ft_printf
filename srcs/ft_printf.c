/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:34:52 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/07 22:34:54 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				parse_string(char **str, va_list ap)
{
	int		i;
	t_mods	modifier;

	(*str)++;
	modifier = get_mods(str, ap);
	if ((i = get_type_specifier(**str)) < 1)
		return (-9000);
//	IF_RETURN(!(i = get_type_specifier(**str)), -9000);
//	IF_RETURN(i == 1, convert_percent(modifier));
//	IF_RETURN(i == 2, convert_d(modifier, ap));
	IF_RETURN(i == 3, convert_c(modifier, ap));
//	IF_RETURN(i == 4, convert_s(modifier, ap));
//	IF_RETURN(i == 5, convert_p(modifier, ap));
//	IF_RETURN(i == 6, convert_o(modifier, ap));
//	IF_RETURN(i == 7, convert_u(modifier, ap));
//	IF_RETURN(i == 8, convert_x(modifier, ap));
//	IF_RETURN(i == 9, convert_f(modifier, ap));
//	IF_RETURN(i == 10, convert_k(modifier, ap));
//	IF_RETURN(i == 11, convert_help(modifier, ap));
	return (42);
}

int				ft_printf(char *str, ...)
{
	int		nbyte;
	va_list	ap;

	nbyte = 0;
	va_start(ap, str);
	while (*str && nbyte >= 0)
	{
		if (*str != '%')
		{
			print_one(&str);
			nbyte++;
		}
		else
		{
			nbyte += parse_string(&str, ap);
			str++;
		}
	}
	IF_THEN(nbyte < 0, errors(1, &str));
	va_end(ap);
	return (nbyte);
}
