/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:34:38 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/26 16:59:07 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

/*
**checks for working libc printf funcitons
*/

int		main(void)
{
	int		a1;
	int		a2;
	int		b1;
	int		b2;
	int		c1;
	int		c2;
	int		n1;
	int		n2;
	char	d;
	char	e;
	char	f;
	char	*s1;
	char	*s2;
	double	x;
	float	y;

	a1 = 1;
	a2 = 2;
	b1 = 10;
	b2 = -20;
	c1 = 100;
	c2 = -200;
	d = 'A';
	e = 'B';
	f = 'C';
	s1 = "hi";
	s2 = "hello";
	x = 1.1;
	y = 3.14;

/*
**	printf("% -d.%-d.%-d\n% -c.%-c\n\n", a, b , c, d, e);
**	printf("%+ c.%-0 c.%      c", 49, e, 'g');
**	printf("%-+0.c.%-+0c.%-+ 03c.", d, e, f);
**	printf("%-3.6c.%-6.c.%-6.3c.%6.3c.%.3c.%4c.", d, e, f, 'W', 'X', 'Y');
**	printf("%-03c.%-02c.%-01c.",d, e, f);
**	int p = (int)write(1, ".", 1);
**	printf("%d", p);
**	printf("%01c.%1c.%.1c.", d, e, f);
**	printf("%%.%-05%.%+%.%05%.% .5h%.");
**	printf("%#%.");
**	printf("positive:%d, %d, %Ld\n", a1, b1, c1);
**	printf("pos h   :%hd, %hd, %hd\n", a1, b1, c1);
**	printf("pos hh  :%hhd, %hhd, %hhd\n", a1, b1, c1);
**	printf("pos l   :%ld, %ld, %ld\n", a1, b1, c1);
**	printf("pos ll  :%lld, %lld, %lld\n", a1, b1, c1);
**	printf("negative:%d, %d, %Ld\n", a2, b2, c2);
**	printf("neg h   :%hd, %hd\n", a2, b2, c2);
**	printf("neg hh  :%hhd, %hhd, %hhd\n", a2, b2, c2);
**	printf("neg l   :%ld, %ld, %ld\n", a2, b2, c2);
**	printf("neg ll  :%lld, %lld, %lld\n", a2, b2, c2);
**	printf("+ flag p:%+d, %+d, %+d\n", a1, b1, c1);
**	printf("+ flag n:%+d, %+d, %+d\n", a2, b2, c2);
**	printf("sp flag :%      d, % d\n", c1, c2);
**	printf("0 flag  :%000d\n", a1);
**	printf("- flag  :%-d, %-----d\n", b1, b2);
**	int po = printf("...|%c|...\n", '\0');
**	int bo = printf("...|%c|...\n", 0);
**	printf("%d\n", po);
**	printf("%d\n", bo);
**	printf("single flag\n");
**	printf("space	+d:% d\n", n1);
**	printf("space	-d:% d\n", n2);
**	printf("plus	+d:%+d\n", n1);
**	printf("plus	-d:%+d\n", n2);
**	printf("zero	+d:%0d\n", n1);
**	printf("zero	-d:%0d\n", n2);
**	printf("minus	+d:%-d\n", n1);
**	printf("minus	-d:%-d\n", n2);
**	printf("pound	+d:%#d\n", n1);
**	printf("pound	-d:%#d\n\n", n2);
**
**	printf("+ and single flag\n");
**	printf("space +	+d:% +d\n", n1);
**	printf("space +	-d:% +d\n", n2);
**	printf("0 +	+d:%0+d\n", n1);
**	printf("0 +	-d:%0+d\n", n2);
**	printf("- +	+d:%-+d\n", n1);
**	printf("- +	-d:%-+d\n", n2);
**	printf("# +	+d:%#+d\n", n1);
**	printf("# +	-d:%#+d\n\n", n2);
**
**	printf("sapce and single flag\n");
**	printf("0 space	+d:%0 d\n", n1);
**	printf("0 space	-d:%0 d\n", n2);
**	printf("- space	+d:%- d\n", n1);
**	printf("- space	-d:%- d\n", n2);
**	printf("# space	+d:%# d\n", n1);
**	printf("# space	-d:%# d\n\n", n2);
**
**	printf("zero and single flag\n");
**	printf("- 0	+d:%-0d\n", n1);
**	printf("- 0	-d:%-0d\n", n2);
**	printf("# 0	+d:%#0d\n", n1);
**	printf("# 0	-d:%#0d\n\n", n2);
**	pound is useless here
**	printf("minus and single flag\n");
**	printf("# -	+d:%#-d\n", n1);
**	printf("# -	-d:%#-d\n", n2);
**
**	printf("flags with width\n");
**	printf("single flag width 4\n");
**	printf("space	d:% 4d\n", n1);
**	printf("space 6w d:% 6d.\n", 555);
**	printf("space 4w d:% 4d.\n", 555);
**	printf("space 2w d:% 2d.\n\n", 555);
**	printf("nspce 6w d:%6d.\n", 676);
**	printf("nspce 4w d:%4d.\n", 676);
**	printf("nspce 2w d:%2d.\n\n", 676);
**	printf("nspce 6w d:%6d.\n", 76);
**	printf("nspce 4w d:%4d.\n", 76);
**	printf("nspce 2w d:%2d.\n\n", 76);
**	printf("space 6w d:%+ 6d.\n", 555);
**	printf("space 4w d:%+ 4d.\n", 555);
**	printf("space 2w d:%+ 2d.\n\n", 555);
**	printf("nspce 6w d:%+6d.\n", 676);
**	printf("nspce 4w d:%+4d.\n", 676);
**	printf("nspce 2w d:%+2d.\n\n", 676);
**	printf("nspce 6w d:%+6d.\n", 76);
**	printf("nspce 4w d:%+4d.\n", 76);
**	printf("nspce 2w d:%+2d.\n\n", 76);
**	printf("np  6w d:%6.d.\n", 555);
**	printf("4p  8w d:%8.4d.\n", 555);
**	printf("2p  2w d:%2.2d.\n\n", 555);
**	printf("minus    2w d:%-2d.\n", 555);
**	printf("minus +  2w d:%-+2d.\n", 555);
**	printf("minus sp 2w d:%- 2d.\n", 555);
**	printf("minus +5p  2w d:%-+2.5d.\n", 555);
**	printf("minus sp5p 2w d:%- 2.5d.\n", 555);
**	printf("neg minus    2w d:%-2d.\n", -555);
**	printf("neg minus +  2w d:%-+2d.\n", -555);
**	printf("neg minus sp 2w d:%- 2d.\n", -555);
**	printf("neg minus +5p  2w d:%-+2.5d.\n", -555);
**	printf("neg minus sp5p 2w d:%- 2.5d.\n", -555);
**	printf("minus 5w d:%-5d.\n\n", 555);
**	printf("minus 2p d:%-.2d.\n", 666);
**	printf("minus 5p d:%-.5d.\n\n", 666);
**	printf("6p  nw d:%.6d.\n", 676);
**	printf("4p  8w d:%8.4d.\n", 676);
**	printf("2p  2w d:%2.2d.\n\n", 676);
**	printf("6p  nw d:%.6d.\n", 76);
**	printf("4p  8w d:%8.4d.\n", 76);
**	printf("2p  2w d:%2.2d.\n\n", 76);
**	printf("space	d:% 4d\n", n2);
**	printf("plus	d:%+4d\n", n1);
**	printf("plus	d:%+4d\n", n2);
**	printf("zero	d:%04d\n", n1);
**	printf("zero	d:%04d\n", n2);
**	printf("minus	d:%-4d\n", n1);
**	printf("minus	d:%-4d\n\n", n2);
**
**	printf("+ and single flag width 4\n");
**	printf("space +	d:% +4d\n", n1);
**	printf("space +	d:% +4d\n", n2);
**	printf("0 +	d:%0+4d\n", n1);
**	printf("0 +	d:%0+4d\n", n2);
**	printf("- +	d:%-+4d\n", n1);
**	printf("- +	d:%-+4d\n\n", n2);
**
**	printf("sapce and single flag width 4\n");
**	printf("0 space	+d:%0 4d\n", n1);
**	printf("0 space	-d:%0 4d\n", n2);
**	printf("- space	+d:%- 4d\n", n1);
**	printf("- space	-d:%- 4d\n\n", n2);
**
**	printf("zero and single flag width 4\n");
**	printf("- 0	+d:%-04d\n", n1);
**	printf("- 0	-d:%-04d\n\n", n2);
**
**	printf("percision\n");
**	printf(".1 :%.1d\n", n1);
**	printf(".1 :%.1d\n", n2);
**	printf(".2 :%.2d\n", n1);
**	printf(".2 :%.2d\n", n2);
**	printf(".5 :%.5d\n", n1);
**	printf(".5 :%.5d\n\n", n2);
**
**	printf("width with zero flag and plus\n");
**	printf("1 :%+01d\n", n1);
**	printf("1 :%+01d\n", n2);
**	printf("3 :%+03d\n", n1);
**	printf("3 :%+03d\n", n2);
**	printf("10:%+010d\n", n1);
**	printf("10:%+010d\n", n2);
**	printf("-5:%+0-5d\n", n1);
**	printf("-5:%+0-5d\n\n", n2);
**
**	printf("width with zero flag and plus\n");
**	printf("01 :%+01d\n", n1);
**	printf("01 :%+01d\n", n2);
**	printf(" 1 :%+ 1d\n", n1);
**	printf(" 1 :%+ 1d\n", n2);
**	printf("03 :%+03d\n", n1);
**	printf("03 :%+03d\n", n2);
**	printf(" 3 :%+ 3d\n", n1);
**	printf(" 3 :%+ 3d\n", n2);
**	printf("010:%+010d\n", n1);
**	printf("010:%+010d\n", n2);
**	printf(" 10:%+ 10d\n", n1);
**	printf(" 10:%+ 10d\n", n2);
**	printf("5 :%+5d\n", n1);
**	printf("5 :%+5d\n\n", n2);
**	printf("5.8 :%+5.8d\n", n1);
**	printf("5.8 :%+5.8d\n", n2);
**	printf("5.4 :%+5.4d\n", n1);
**	printf("5.4 :%+5.4d\n\n", n2);
**	printf("10.8 :%+10.8d\n", n1);
**	printf("10.8 :%+10.8d\n", n2);
**	printf("10.4 :%+10.4d\n", n1);
**	printf("10.4 :%+10.4d\n\n", n2);
**	printf("   SP   :% d.\n", 60);
**	printf("   SP4w :% 4d.\n", 61);
**	printf("   .5   :%.5d.\n", 70);
**	printf("   4w   :%4d.\n", 80);
**	printf(" SP6w  +:%+ 6d.\n", 90);
**	printf("negSP   :% d.\n", -64);
**	printf("neg.5   :%.5d.\n", -74);
**	printf("neg4w   :%4d.\n", -84);
**	printf("neg6w  +:%+6d.\n\n", -94);
**	printf("   SP   :% d.\n", 1160);
**	printf("   .5   :%.5d.\n", 1170);
**	printf("   4w   :%4d.\n", 1180);
**	printf(" SP6w.7+:%+ 6.7d.\n", 1190);
**	printf("negSP   :% d.\n", -9164);
**	printf("neg.5   :%.5d.\n", -9174);
**	printf("neg4w   :%4d.\n", -9184);
**	printf("neg6w.7+:%+6.7d.\n", -9194);
**	printf("10w plus space:% +10d\n", n1);
**	printf("10w plus space:% +10d\n", n2);
**	printf("10w space     :% 10d\n", n1);
**	printf("10w space     :% 10d\n\n", n2);
**
**	printf("percision and width of 8\n");
**	printf(".1 :%8.1d\n", n1);
**	printf(".1 :%8.1d\n", n2);
**	printf(".2 :%8.2d\n", n1);
**	printf(".2 :%8.2d\n", n2);
**	printf(".5 :%8.5d\n", n1);
**	printf(".5 :%8.5d\n\n", n2);
**	printf("percision and width of 4\n");
**	printf(".1 :%4.1d\n", n1);
**	printf(".1 :%4.1d\n", n2);
**	printf(".2 :%4.2d\n", n1);
**	printf(".2 :%4.2d\n", n2);
**	printf(".5 :%4.5d\n", n1);
**	printf(".5 :%4.5d\n\n", n2);
**	printf("percision and width of 2\n");
**	printf(".1 :%2.1d\n", n1);
**	printf(".1 :%2.1d\n", n2);
**	printf(".2 :%2.2d\n", n1);
**	printf(".2 :%2.2d\n", n2);
**	printf(".5 :%2.5d\n", n1);
**	printf(".5 :%2.5d\n\n", n2);
**	printf("percision 7 and width of ?\n");
**	printf(".7    :%0 .7d\n", n1);
**	printf(".7    :%0 .7d\n", n2);
**	printf(".7 10w:%0 10.7d\n", n1);
**	printf(".7 10w:%0 10.7d\n", n2);
**	printf(".7 4w :%0 4.7d\n", n1);
**	printf(".7 4w :%0 4.7d\n\n", n2);
**
**	printf("-            :%-d.\n", n1);
**	printf("-            :%-d.\n", n2);
**	printf("- space      :%- d.\n", n1);
**	printf("- space      :%- d.\n", n2);
**	printf("-+space      :%-+ d.\n", n1);
**	printf("-+space      :%-+ d.\n", n2);
**	printf("1w-          :%-1d.\n", n1);
**	printf("1w-          :%-1d.\n", n2);
**	printf("1w- space    :%- 1d.\n", n1);
**	printf("1w- space    :%- 1d.\n", n2);
**	printf("1w-+space    :%-+ 1d.\n", n1);
**	printf("1w-+space    :%-+ 1d.\n", n2);
**	printf("5w-          :%-5d.\n", n1);
**	printf("5w-          :%-5d.\n", n2);
**	printf("5w- space    :%- 5d.\n", n1);
**	printf("5w- space    :%- 5d.\n", n2);
**	printf("5w-+space    :%-+ 5d.\n", n1);
**	printf("5w-+space    :%-+ 5d.\n", n2);
**	printf("10w-         :%-10d.\n", n1);
**	printf("10w-         :%-10d.\n", n2);
**	printf("10w- space   :%- 10d.\n", n1);
**	printf("10w- space   :%- 10d.\n", n2);
**	printf("10w-+space   :%-+ 10d.\n", n1);
**	printf("10w-+space   :%-+ 10d.\n\n", n2);
**
**	printf("-         .2 :%-.2d.\n", n1);
**	printf("-         .2 :%-.2d.\n", n2);
**	printf("- space   .2 :%- .2d.\n", n1);
**	printf("- space   .2 :%- .2d.\n", n2);
**	printf("-+space   .2 :%-+ .2d.\n", n1);
**	printf("-+space   .2 :%-+ .2d.\n", n2);
**	printf("1w-       .2 :%-1.2d.\n", n1);
**	printf("1w-       .2 :%-1.2d.\n", n2);
**	printf("1w- space .2 :%- 1.2d.\n", n1);
**	printf("1w- space .2 :%- 1.2d.\n", n2);
**	printf("1w-+space .2 :%-+ 1.2d.\n", n1);
**	printf("1w-+space .2 :%-+ 1.2d.\n", n2);
**	printf("5w-       .2 :%-5.2d.\n", n1);
**	printf("5w-       .2 :%-5.2d.\n", n2);
**	printf("5w- space .2 :%- 5.2d.\n", n1);
**	printf("5w- space .2 :%- 5.2d.\n", n2);
**	printf("5w-+space .2 :%-+ 5.2d.\n", n1);
**	printf("5w-+space .2 :%-+ 5.2d.\n", n2);
**	printf("10w-      .2 :%-10.2d.\n", n1);
**	printf("10w-      .2 :%-10.2d.\n", n2);
**	printf("10w- space.2 :%- 10.2d.\n", n1);
**	printf("10w- space.2 :%- 10.2d.\n", n2);
**	printf("10w-+space.2 :%-+ 10.2d.\n", n1);
**	printf("10w-+space.2 :%-+ 10.2d.\n\n", n2);
**
**	printf("-         .6 :%-.6d.\n", n1);
**	printf("-         .6 :%-.6d.\n", n2);
**	printf("- space   .6 :%- .6d.\n", n1);
**	printf("- space   .6 :%- .6d.\n", n2);
**	printf("-+space   .6 :%-+ .6d.\n", n1);
**	printf("-+space   .6 :%-+ .6d.\n", n2);
**	printf("1w-       .6 :%-1.6d.\n", n1);
**	printf("1w-       .6 :%-1.6d.\n", n2);
**	printf("1w- space .6 :%- 1.6d.\n", n1);
**	printf("1w- space .6 :%- 1.6d.\n", n2);
**	printf("1w-+space .6 :%-+ 1.6d.\n", n1);
**	printf("1w-+space .6 :%-+ 1.6d.\n", n2);
**	printf("5w-       .6 :%-5.6d.\n", n1);
**	printf("5w-       .6 :%-5.6d.\n", n2);
**	printf("5w- space .6 :%- 5.6d.\n", n1);
**	printf("5w- space .6 :%- 5.6d.\n", n2);
**	printf("5w-+space .6 :%-+ 5.6d.\n", n1);
**	printf("5w-+space .6 :%-+ 5.6d.\n", n2);
**	printf("10w-      .6 :%-10.6d.\n", n1);
**	printf("10w-      .6 :%-10.6d.\n", n2);
**	printf("10w- space.6 :%- 10.6d.\n", n1);
**	printf("10w- space.6 :%- 10.6d.\n", n2);
**	printf("10w-+space.6 :%-+ 10.6d.\n", n1);
**	printf("10w-+space.6 :%-+ 10.6d.\n\n", n2);
**
**	printf(".4         :%-.8d.\n", n1);
**	printf(".4         :%-.8d.\n", n2);
**
**	printf(".5         :%.5d.\n", n1);
**	printf(".5         :%.5d.\n", n2);
**	printf(".5space    :% .5d.\n", n1);
**	printf(".5space    :% .5d.\n", n2);
**	printf(".5space+   :% +.5d.\n", n1);
**	printf(".5space+   :% +.5d.\n", n2);
**	printf(".5zero     :%0.5d.\n", n1);
**	printf(".5zero     :%0.5d.\n", n2);
**	printf(".5zeroSP   :% 0.5d.\n", n1);
**	printf(".5zeroSP   :% 0.5d.\n", n2);
**	printf("5w.5space  :% 5.5d.\n", n1);
**	printf("5w.5space  :% 5.5d.\n", n2);
**	printf("5w.5space+ :% +5.5d.\n", n1);
**	printf("5w.5space+ :% +5.5d.\n", n2);
**	printf("5w.5zero   :%05.5d.\n", n1);
**	printf("5w.5zero   :%05.5d.\n", n2);
**	printf("5w.5zeroSP :%0 5.5d.\n", n1);
**	printf("5w.5zeroSP :% 05.5d.\n", n2);
**	printf("10w.5space :% 10.5d.\n", n1);
**	printf("10w.5space :% 10.5d.\n", n2);
**	printf("10w.5space+:% +10.5d.\n", n1);
**	printf("10w.5space+:% +10.5d.\n", n2);
**	printf("10w.5zero  :%010.5d.\n", n1);
**	printf("10w.5zero  :%010.5d.\n", n2);
**	printf("10w.5zeroSP:%0 10.5d.\n", n1);
**	printf("10w.5zeroSP:%0 10.5d.\n", n2);
**	printf("%d\n", n1);
**	printf("%d\n", n2);
**	printf("%d\n", n1);
**	printf("%d\n", n2);
**	printf("%d\n", n1);
**	printf("%d\n", n2);
**	printf("%d\n", n1);
**	printf("%d\n", n2);
**	printf("%5%\n");
**	printf("%05%\n");
**
**	printf(".% s..", "string test.\n");
**	printf(".%        s..", "test.\n");
**	printf("%+s", "test.\n");
**	printf("%-05c.\n%0.5c.\n\n", 'a', 'b');
**	printf("%-05s.\n%0.5s.\n%-05.5s.\n\n", "abc", "abc", "abc");
**	printf("%-05s.\n%0.5s.\n%-05.5s.\n\n", "abcdef", "abcdef", "abcdef");
**	printf("%-010s.\n%0.5s.\n%-010.5s.\n\n", "aXcdef", "aXcdef", "aXcdef");
**	printf("%-05s.\n%0.10s.\n%-05.10s.\n\n", "aXYcdef", "aXYcdef", "aXYcdef");
**
**	printf(".%-10.5s.\n", "123456");
**	printf(".%-6.5s.\n\n\n", "123456");
**
**	ft_printf("these are tests for my own printf vs libc printf\n\n");
*/

	char	c;
	char	*s;
	int		i;

	c = 'X';
	s = "%%c test :%c.\n";
	i = ft_printf("regular string test\n");
	n1 = 400;
	n2 = -400;

/*
**	ft_printf("%%c test :%c.\n", c);
**	printf("%%c test :%c. <<\n\n", c);
**	ft_printf("%%%% test :%%.\n");
**	printf("%%%% test :%%. <<\n\n");
**	ft_printf("%%d test :% .2d.\n", -20);
**	printf("%%d test :% .2d. <<\n\n", -20);
**	ft_printf("%%d test :%.3d.\n", -21);
**	printf("%%d test :%.3d. <<\n\n", -21);
**	ft_printf("%%d test :% .4d.\n", -22);
**	printf("%%d test :% .4d. <<\n\n", -22);
**	ft_printf("%%d test :%+.2d.\n", 23);
**	printf("%%d test :%+.2d. <<\n\n", 23);
**	ft_printf("%%d test :%.3d.\n", 24);
**	printf("%%d test :%.3d. <<\n\n", 24);
**	ft_printf("%%d test :%+.4d.\n", 25);
**	printf("%%d test :%+.4d. <<\n\n", 25);
**	ft_printf("%%d test :%2d.\n", -26);
**	printf("%%d test :%2d. <<\n\n", -26);
**	ft_printf("%%d test :%10.4d.\n", -27);
**	printf("%%d test :%10.4d. <<\n\n", -27);
**	ft_printf("%%d test :%4.5d.\n", -28);
**	printf("%%d test :%4.5d. <<\n\n", -28);
**	ft_printf("%%d test :%+2d.\n", 29);
**	printf("%%d test :%+2d. <<\n\n", 29);
**	ft_printf("%%d test :%3d.\n", 30);
**	printf("%%d test :%3d. <<\n\n", 30);
**	ft_printf("%%d test :%+4d.\n", -31);
**	printf("%%d test :%+4d. <<\n\n", -31);
**	ft_printf(".5         :%.5d.\n", n1);
**	ft_printf(".5         :%.5d.\n", n2);
**	ft_printf(".5space    :% .5d.\n", n1);
**	ft_printf(".5space    :% .5d.\n", n2);
**	ft_printf(".5space+   :% +.5d.\n", n1);
**	ft_printf(".5space+   :% +.5d.\n", n2);
**	ft_printf(".5zero     :%0.5d.\n", n1);
**	ft_printf(".5zero     :%0.5d.\n", n2);
**	ft_printf(".5zeroSP   :% 0.5d.\n", n1);
**	ft_printf(".5zeroSP   :% 0.5d.\n", n2);
**	ft_printf("5w.5space  :% 5.5d.\n", n1);
**	ft_printf("5w.5space  :% 5.5d.\n", n2);
**	ft_printf("5w.5space+ :% +5.5d.\n", n1);
**	ft_printf("5w.5space+ :% +5.5d.\n", n2);
**	ft_printf("5w.5zero   :%05.5d.\n", n1);
**	ft_printf("5w.5zero   :%05.5d.\n", n2);
**	ft_printf("5w.5zeroSP :%0 5.5d.\n", n1);
**	ft_printf("5w.5zeroSP :% 05.5d.\n", n2);
**	ft_printf("10w.5space :% 10.5d.\n", n1);
**	ft_printf("10w.5space :% 10.5d.\n", n2);
**	ft_printf("10w.5space+:% +10.5d.<<\n", n1);
**	ft_printf("10w.5space+:% +10.5d.<<\n", n2);
**	ft_printf("10w.5zero  :%010.5d.<<\n", n1);
**	ft_printf("10w.5zero  :%010.5d.\n", n2);
**	ft_printf("10w.5zeroSP:%0 10.5d.\n", n1);
**	ft_printf("10w.5zeroSP:%0 10.5d.\n", n2);
**	ft_printf("%10s is a string\n\n", NULL);
**	ft_printf("% 10.5d\n", 4242);
**	ft_printf("%+10.5d\n", 4242);
**	ft_printf("%03.2d\n", -1);
**	ft_printf("%.d. %.0d\n", 0, 0);
**	printf("%d. %d\n", 0, 0);
**	ft_printf("%5.d %5.0d\n", 0, 0);
**	printf("%5.d %5.0d\n", 0, 0);
**	ft_printf("%+d", 0);
**	i = ft_printf("%05d", 42);
**	ft_printf("%0+5d\n", 42);
**	i = ft_printf("%05d", -42);
**	ft_printf("%0+5d\n", -42);
**
**	ft_printf("%10.5d\n", -216);
**	printf("%10.5d\n", -216);
**	printf(".\n\nbytes: %d\n", i);
**	i = ft_printf("%10.5i", -216);
**	i = ft_printf("%0+5d", 42);
*/

	ft_printf("\"");
	i = ft_printf("% 05d", 43);
	ft_printf("\"");
	ft_printf(" <- ft_printf.bytes -> %d\n", i);
	printf("\"");
	i = printf("% 05d", 43);
	printf("\"");
	printf(" <-    printf.bytes -> %d\n\n", i);

	ft_printf("\"");
	i = ft_printf("% 03d", 0);
	ft_printf("\"");
	ft_printf("   <- ft_printf.bytes -> %d\n", i);
	printf("\"");
	i = printf("% 03d", 0);
	printf("\"");
	printf("   <-    printf.bytes -> %d\n\n", i);

	return (0);
}
