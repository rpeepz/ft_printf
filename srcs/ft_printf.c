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

int				parse_string(char **str, va_list ap, int n)
{
	int		i;
	t_mods	modifier;

	(*str)++;
	modifier = get_mods(str, ap);
	IF_THEN(!(i = get_type_specifier(**str)), n -= 9000);
	while (n >= 0 && i)
	{
		BREAK(i == 1, n += convert_percent(modifier));
		BREAK(i == 2, n += convert_d(modifier, ap) && (*str)++);
		BREAK(i == 3, n += convert_c(modifier, ap) && (*str)++);
		BREAK(i == 4, n += convert_s(modifier, ap) && (*str)++);
		BREAK(i == 5, n += convert_p(modifier, ap) && (*str)++);
		BREAK(i == 6, n += convert_o(modifier, ap) && (*str)++);
		BREAK(i == 7, n += convert_u(modifier, ap) && (*str)++);
		BREAK(i == 8, n += convert_x(modifier, ap) && (*str)++);
		BREAK(i == 9, n += convert_f(modifier, ap) && (*str)++);
		BREAK(i == 10, n += convert_k(modifier, ap) && (*str)++);
		BREAK(i == 11, n += convert_help(modifier, ap) && (*str)++);
	}
	return (n >= 0 ? n : -1);
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
			nbyte += parse_string(&str, ap, 0);
	}
	IF_THEN(nbyte < 0, errors(1, &str));
	va_end(ap);
	return (nbyte);
}
