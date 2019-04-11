/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:59:55 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/09 20:03:58 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**int			table(t_mods*, va_list){
**		convert_percent,
**		convert_c,
**		convert_d,
**		convert_s,
**		convert_p,
**		convert_o,
**		convert_u,
**		convert_x,
**		convert_f,
**		convert_k,
**		convert_help,
**};
*/
t_dispatch_specifier	g_conversions[] =
{
	{'d', convert_d},
	{'i', convert_d},
	{'c', convert_c},
	{'s', convert_s},
	{'p', convert_p},
	{'o', convert_o},
	{'u', convert_u},
	{'x', convert_x},
	{'X', convert_c},
	{'f', convert_f},
	{'F', convert_f},
	{'k', convert_k},
	{'K', convert_k},
	{'?', convert_help},
	{0, NULL}
};
