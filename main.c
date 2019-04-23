/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:34:38 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/22 14:39:45 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	c;
	char	*s;
	int		i;
	int		n1;
	int		n2;

	c = 'X';
	s = "%%c test :%c.\n";
	i = ft_printf("regular string test\n");
	n1 = 400;
	n2 = -400;
//	ft_printf("%%c test :%c.\n", c);
//	printf("%%c test :%c. <<\n\n", c);
//	ft_printf("%%%% test :%%.\n");
//	printf("%%%% test :%%. <<\n\n");
//	ft_printf("%%d test :% .2d.\n", -20);
//	printf("%%d test :% .2d. <<\n\n", -20);
//	ft_printf("%%d test :%.3d.\n", -21);
//	printf("%%d test :%.3d. <<\n\n", -21);
//	ft_printf("%%d test :% .4d.\n", -22);
//	printf("%%d test :% .4d. <<\n\n", -22);
//	ft_printf("%%d test :%+.2d.\n", 23);
//	printf("%%d test :%+.2d. <<\n\n", 23);
//	ft_printf("%%d test :%.3d.\n", 24);
//	printf("%%d test :%.3d. <<\n\n", 24);
//	ft_printf("%%d test :%+.4d.\n", 25);
//	printf("%%d test :%+.4d. <<\n\n", 25);
//	ft_printf("%%d test :%2d.\n", -26);
//	printf("%%d test :%2d. <<\n\n", -26);
//	ft_printf("%%d test :%10.4d.\n", -27);
//	printf("%%d test :%10.4d. <<\n\n", -27);
//	ft_printf("%%d test :%4.5d.\n", -28);
//	printf("%%d test :%4.5d. <<\n\n", -28);
//	ft_printf("%%d test :%+2d.\n", 29);
//	printf("%%d test :%+2d. <<\n\n", 29);
//	ft_printf("%%d test :%3d.\n", 30);
//	printf("%%d test :%3d. <<\n\n", 30);
//	ft_printf("%%d test :%+4d.\n", -31);
//	printf("%%d test :%+4d. <<\n\n", -31);
//	ft_printf(".5         :%.5d.\n", n1);
//	ft_printf(".5         :%.5d.\n", n2);
//	ft_printf(".5space    :% .5d.\n", n1);
//	ft_printf(".5space    :% .5d.\n", n2);
//	ft_printf(".5space+   :% +.5d.\n", n1);
//	ft_printf(".5space+   :% +.5d.\n", n2);
//	ft_printf(".5zero     :%0.5d.\n", n1);
//	ft_printf(".5zero     :%0.5d.\n", n2);
//	ft_printf(".5zeroSP   :% 0.5d.\n", n1);
//	ft_printf(".5zeroSP   :% 0.5d.\n", n2);
//	ft_printf("5w.5space  :% 5.5d.\n", n1);
//	ft_printf("5w.5space  :% 5.5d.\n", n2);
//	ft_printf("5w.5space+ :% +5.5d.\n", n1);
//	ft_printf("5w.5space+ :% +5.5d.\n", n2);
//	ft_printf("5w.5zero   :%05.5d.\n", n1);
//	ft_printf("5w.5zero   :%05.5d.\n", n2);
//	ft_printf("5w.5zeroSP :%0 5.5d.\n", n1);
//	ft_printf("5w.5zeroSP :% 05.5d.\n", n2);
//	ft_printf("10w.5space :% 10.5d.\n", n1);
//	ft_printf("10w.5space :% 10.5d.\n", n2);
//	ft_printf("10w.5space+:% +10.5d.<<\n", n1);
//	ft_printf("10w.5space+:% +10.5d.<<\n", n2);
//	ft_printf("10w.5zero  :%010.5d.<<\n", n1);
//	ft_printf("10w.5zero  :%010.5d.\n", n2);
//	ft_printf("10w.5zeroSP:%0 10.5d.\n", n1);
//	ft_printf("10w.5zeroSP:%0 10.5d.\n", n2);
	ft_printf("%10s is a string", NULL);
	return (0);
}
