/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:15:45 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/22 18:42:29 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

const static char	g_basetable[] = "0123456789ABCDEF";

char	*ft_itoa_base(int32_t n, int base)
{
	int64_t	tmp;
	int		len;
	char	*str;

	IF_RETURN((n == -2147483648), "-2147483648");
	IF_THEN(n < 0, n *= -1);
	tmp = n;
	len = 1;
	while (tmp /= base)
		len++;
	tmp = n;
	IF_THEN(base == 10, len += 1);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		str[len] = g_basetable[(tmp % base)];
		tmp /= base;
	}
	if (n < 0 && base == 10)
		str[0] = '-';
	return (str);
}
