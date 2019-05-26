/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 21:23:44 by rpapagna          #+#    #+#             */
/*   Updated: 2019/05/26 02:02:33 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_sprintf.h"
#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	buf[PAGESIZE];
	
	ft_printf("my spritnf say: ");
	ft_sprintf(buf, "[%15s] [%+10d] [%10c]", "hello world", 123456789, 'D');
	ft_printf("%s\n\n", buf);
	ft_printf("yo spritnf say: ");
	sprintf(buf, "[%15s] [%+10d] [%10c]", "hello world", 123456789, 'D');
	printf("%s\n", buf);
	return (0);
}