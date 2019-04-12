/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:34:38 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/12 16:30:27 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	int		i;
	char	c;
	char	*s;
	
	s = "%%c test: %c.\n";
	c = 'X';
	i = ft_printf("regular string test\n");
	ft_printf("%%c test: %c.\n", c);
	ft_printf(s, c);
	ft_printf("%%%% test: %%.\n");
	ft_printf("%%d test: %d.\n", i);
	return (0);
}
