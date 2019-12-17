#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	char *s = "Bonjour, je suis malade";
	unsigned int u = 453123156;
	unsigned int x = 42324865;
	unsigned int X = 123456865;
	int i = 42689312;
	int d = -1365623632;
	char c = 'c';
	int ret = 0;

	printf("\n---------------Decimaux---------------\n\n");

	printf("true : ");
	printf("#%d%d#", 0, 150);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%d%d#", 0, 150);
	printf("\n\n");

	printf("true : ");
	printf("#%.d#", 0);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.d#", 0);
	printf("\n\n");

	printf("true : ");
	printf("#%20d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%20d#", d);
	printf("\n\n");

	printf("true : ");
	printf("#%020d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%020d#", d);
	printf("\n\n");

	printf("true : ");
	printf("#%4d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%4d#", d);
	printf("\n\n");

	printf("true : ");
	printf("#%.20d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.20d#", d);
	printf("\n\n");

	printf("true : ");
	printf("#%20.4d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%20.4d#", d);
	printf("\n\n");

	printf("true : ");
	printf("#%2.30d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%2.30d#", d);
	printf("\n\n");

	printf("true : ");
	printf("#%030.30d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%030.30d#", d);
	printf("\n\n");

	printf("true : ");
	printf("#%20.4i#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%20.4i#", d);
	printf("\n\n");

	printf("\n---------------Long---------------\n\n");

	printf("true : ");
	printf("#%4i#", i);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%4i#", i);
	printf("\n\n");

	printf("true : ");
	printf("#%.20i#", i);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.20i#", i);
	printf("\n\n");

	printf("true : ");
	printf("#%20.4i#", i);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%20.4i#", i);
	printf("\n\n");

	printf("true : ");
	printf("#%2.30i#", i);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%2.30i#", i);
	printf("\n\n");

	printf("true : ");
	printf("#%030.30i#", i);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%030.30i#", i);
	printf("\n\n");



	printf("\n---------------Unsigned---------------\n\n");

	printf("true : ");
	printf("#%u#", (unsigned int)NULL);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%u#", (unsigned int)NULL);
	printf("\n\n");

	printf("true : ");
	printf("#%u#", UINT_MAX);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%u#", UINT_MAX);
	printf("\n\n");

	printf("true : ");
	printf("#%20u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%20u#", u);
	printf("\n\n");

	printf("true : ");
	printf("#%011u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%011u#", u);
	printf("\n\n");

	printf("true : ");
	printf("#%4u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%4u#", u);
	printf("\n\n");

	printf("true : ");
	printf("#%.15u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.15u#", u);
	printf("\n\n");

	printf("true : ");
	printf("#%.4u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.4u#", u);
	printf("\n\n");

	printf("true : ");
	printf("#%20.4u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%20.4u#", u);
	printf("\n\n");

	printf("\n---------------Hexadecimal---------------\n\n");

	printf("true : ");
	printf("#%x#", (unsigned int)NULL);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%x#", (unsigned int)NULL);
	printf("\n\n");

	printf("true : ");
	printf("#%.x#", (unsigned int)NULL);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.x#", (unsigned int)NULL);
	printf("\n\n");

	printf("true : ");
	printf("#%4x#", x);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%4x#", x);
	printf("\n\n");

	printf("true : ");
	printf("#%30x#", x);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%30x#", x);
	printf("\n\n");

	printf("true : ");
	printf("#%030x#", x);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%030x#", x);
	printf("\n\n");

	printf("true : ");
	printf("#%.3x#", x);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.3x#", x);
	printf("\n\n");

	printf("true : ");
	printf("#%.30x#", x);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.30x#", x);
	printf("\n\n");

	printf("true : ");
	printf("#%5.30x#", x);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%5.30x#", x);
	printf("\n\n");

	printf("true : ");
	printf("#%50.30x#", x);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%50.30x#", x);
	printf("\n\n");

	printf("true : ");
	printf("#%-50.30x#", x);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%-50.30x#", x);
	printf("\n\n");

	printf("true : ");
	printf("#%050.30x#", x);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%050.30x#", x);
	printf("\n\n");

	printf("\n---------------HeXacimal---------------\n\n");

	printf("true : ");
	printf("#%X#", (unsigned int)NULL);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%X#", (unsigned int)NULL);
	printf("\n\n");

	printf("true : ");
	printf("#%4X#", X);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%4X#", X);
	printf("\n\n");

	printf("true : ");
	printf("#%30X#", X);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%30X#", X);
	printf("\n\n");

	printf("true : ");
	printf("#%030X#", X);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%030X#", X);
	printf("\n\n");

	printf("true : ");
	printf("#%.3X#", X);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.3X#", X);
	printf("\n\n");

	printf("true : ");
	printf("#%.30X#", X);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.30X#", X);
	printf("\n\n");

	printf("true : ");
	printf("#%5.30X#", X);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%5.30X#", X);
	printf("\n\n");

	printf("true : ");
	printf("#%50.30X#", X);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%50.30X#", X);
	printf("\n\n");

	printf("true : ");
	printf("#%-50.30X#", X);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%-50.30X#", X);
	printf("\n\n");

	printf("true : ");
	printf("#%050.30X#", X);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%050.30X#", X);
	printf("\n\n");

	printf("\n---------------Pointeur---------------\n\n");

	printf("true : ");
	printf("#%p#", NULL);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%p#", NULL);
	printf("\n\n");

	printf("true : ");
	printf("#%4p#", &d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%4p#", &d);
	printf("\n\n");

	printf("true : ");
	printf("#%30p#", &u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%30p#", &u);
	printf("\n\n");

	printf("true : ");
	printf("#%-30p#", &u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%-30p#", &u);
	printf("\n\n");

	printf("\n---------------Characteres---------------\n\n");

	printf("true : ");
	ret = printf("#%.c#\n", 0);
	printf("ret : %d\n", ret);
	printf("\n");
	ft_printf("ft_  : ");
	ret = ft_printf("#%.c#\n", 0);
	printf("ret : %d\n", ret);
	printf("\n\n");

	printf("true : ");
	ret = printf("#%.c#\n", c);
	printf("ret : %d\n", ret);
	printf("\n");
	ft_printf("ft_  : ");
	ret = ft_printf("#%.c#\n", c);
	printf("ret : %d\n", ret);
	printf("\n\n");

	printf("true : ");
	ret = printf("#%.0c#\n", c);
	printf("ret : %d\n", ret);
	printf("\n");
	ft_printf("ft_  : ");
	ret = ft_printf("#%.0c#\n", c);
	printf("ret : %d\n", ret);
	printf("\n\n");

	printf("true : ");
	ret = printf("#%c%c#\n", 'c', 0);
	printf("ret : %d\n", ret);
	printf("\n");
	ft_printf("ft_  : ");
	ret = ft_printf("#%c%c#\n", 'c', 0);
	printf("ret : %d\n", ret);
	printf("\n\n");

	printf("true : ");
	printf("#%20c#", c);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%20c#", c);
	printf("\n\n");

	printf("true : ");
	printf("#%4c#", c);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%4c#", c);
	printf("\n\n");

	printf("true : ");
	printf("#%-20c#", c);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%-20c#", c);
	printf("\n\n");

	printf("true : ");
	ret = printf("#%%#\n");
	printf("ret : %d\n", ret);
	printf("\n");
	ft_printf("ft_  : ");
	ret = ft_printf("#%%#\n");
	printf("ret : %d\n", ret);
	printf("\n\n");

	printf("true : ");
	ret = printf("#%.%#\n");
	printf("ret : %d\n", ret);
	printf("\n");
	ft_printf("ft_  : ");
	ret = ft_printf("#%.%#\n");
	printf("ret : %d\n", ret);
	printf("\n\n");

	printf("true : ");
	ret = printf("#%5.%#\n");
	printf("ret : %d\n", ret);
	printf("\n");
	ft_printf("ft_  : ");
	ret = ft_printf("#%5.%#\n");
	printf("ret : %d\n", ret);
	printf("\n\n");

	printf("true : ");
	ret = printf("#%.5%#\n");
	printf("ret : %d\n", ret);
	printf("\n");
	ft_printf("ft_  : ");
	ret = ft_printf("#%.5%#\n");
	printf("ret : %d\n", ret);
	printf("\n\n");

	printf("true : ");
	ret = printf("#%5.0%#\n");
	printf("ret : %d\n", ret);
	printf("\n");
	ft_printf("ft_  : ");
	ret = ft_printf("#%5.0%#\n");
	printf("ret : %d\n", ret);
	printf("\n\n");

	printf("---------------Chaine--De--Caractere---------------\n\n");

	printf("true : ");
	printf("#%20s#", NULL);
	printf("\n");
	ft_printf("ft_  : ");                     //1
	ft_printf("#%20s#", NULL);
	printf("\n\n");

	printf("true : ");
	printf("#%.s#", s);
	printf("\n");
	ft_printf("ft_  : ");                     //1
	ft_printf("#%.s#", s);
	printf("\n\n");

	printf("true : ");
	printf("#%30s#", s);
	printf("\n");                             //2
	ft_printf("ft_  : ");
	ft_printf("#%30s#", s);
	printf("\n\n");

	printf("true : ");
	printf("#%.4s#", s);
	printf("\n");                             //3
	ft_printf("ft_  : ");
	ft_printf("#%.4s#", s);
	printf("\n\n");

	printf("true : ");
	printf("#%.30s#", s);
	printf("\n");                             //4
	ft_printf("ft_  : ");
	ft_printf("#%.30s#", s);
	printf("\n\n");

	printf("true : ");
	printf("#%*.4s#", 20, s);
	printf("\n");                             //5
	ft_printf("ft_  : ");
	ft_printf("#%*.4s#", 20, s);
	printf("\n\n");

	printf("true : ");
	printf("#%-s#", s);
	printf("\n");                              //6
	ft_printf("ft_  : ");
	ft_printf("#%-s#", s);
	printf("\n\n");

	printf("true : ");
	printf("#%-30s#", s);
	printf("\n");                              //7
	ft_printf("ft_  : ");
	ft_printf("#%-30s#", s);
	printf("\n\n");

	printf("true : ");
	printf("#%-.4s#", s);
	printf("\n");                              //8
	ft_printf("ft_  : ");
	ft_printf("#%-.4s#", s);
	printf("\n\n");

	printf("true : ");
	printf("#%-.30s#", s);
	printf("\n");                              //9
	ft_printf("ft_  : ");
	ft_printf("#%-.30s#", s);
	printf("\n\n");


	printf("---------------Astrid-False--------------\n\n");

	printf("true : ");
	printf("#%08.4d#", -12456);
	printf("\n");                              //9
	ft_printf("ft_  : ");
	ft_printf("#%08.4d#", -12456);
	printf("\n\n");

	printf("true : ");
	printf("#%03i#", -1);
	printf("\n");                              //9
	ft_printf("ft_  : ");
	ft_printf("#%03i#", -1);
	printf("\n\n");

	return (0);
}
