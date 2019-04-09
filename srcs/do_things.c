/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_things.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:46:20 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/08 20:46:21 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_one(char **str)
{
	ft_putchar(**str);
	(*str)++;
}

void		errors(int err_num, char **str)
{
	if (err_num == 1)
		ft_printf("%c <-invalid specifier", **str);
}

void		set_flags(t_flag *flags, char c)
{
	if (c == ' ')
		flags->space = 1;
	else if (c == '#')
		flags->pound = 1;
	else if (c == '+')
		flags->fplus = 1;
	else if (c == '-')
		flags->minus = 1;
	else if (c == '0')
		flags->fzero = 1;
}
