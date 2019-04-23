/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:59:06 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/22 15:07:06 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	s	The char* argument is expected to be a pointer to an array of character
**		type (pointer to a string).
**		Characters from the array are written up to (but not including) a
**		terminating NULL character; if a precision is specified, no more than
**		the number specified are written.
**		If a precision is given, no null character need be present;
**		if the precision is not specified, or is greater than the size of the
**		array, the array must contain a terminating NUL character.
*/

static int	left_justify(t_mods mod, char *s)
{
	int		nbyte;

	nbyte = 0;
	nbyte += (int)write(1, s, ft_strlen(s));
	while (nbyte < mod.width)
		nbyte += (int)write(1, " ", 1);
	return (nbyte);
}

static int	right_justify(t_mods mod, char *s)
{
	int		nbyte;

	nbyte = 0;
	if (mod.flags.fzero == 1)
	{
		while (mod.width-- > (int)ft_strlen(s))
			nbyte += (int)write(1, "0", 1);
	}
	else
	{
		while (mod.width-- > (int)ft_strlen(s))
			nbyte += (int)write(1, " ", 1);
	}
	return (nbyte += (int)write(1, s, ft_strlen(s)));
}

int			convert_s(t_mods modifiers, va_list ap)
{
	char	*s;
	char	*s2;
	int		nbyte;

	s = va_arg(ap, char *);
	IF_THEN(!s, s = "(null)");
	nbyte = 0;
	if (modifiers.precision >= 0 && modifiers.precision < (int)ft_strlen(s))
		s2 = ft_strndup(s, modifiers.precision);
	else
		s2 = ft_strdup(s);
	if (modifiers.flags.minus == 1)
	{
		if (modifiers.width <= (int)ft_strlen(s2))
			nbyte += (int)write(1, s2, ft_strlen(s2));
		else
			nbyte += left_justify(modifiers, s2);
		IF_RETURN(1, (ft_pipewrench("-s", s2) + nbyte) - 1);
	}
	if (modifiers.width > (int)ft_strlen(s2))
		nbyte += right_justify(modifiers, s2);
	else
		nbyte += (int)write(1, s2, ft_strlen(s2));
	IF_RETURN(1, (ft_pipewrench("-s", s2) + nbyte) - 1);
}
