/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:34:38 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/10 22:36:17 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	int		i;

	i = ft_printf("test");
	ft_printf("%c\n", 'a');
	char *s = "hello. this is a char: %c test\n";
	char c = 'X';
	ft_printf(s, c);
	ft_printf("%%.%%%%.\n");
	return (0);
}
