#include "ft_printf.h"

int main(void)
{
	char *s = "Bonjour, je suis malade";
	unsigned int u = 453123156;
	unsigned int x = 42324865;
	unsigned int X = 123456865;
	int d = -1365623632;
	char c = 'c';

	printf("\n---------------Decimaux---------------\n\n");

	printf("true : ");
	printf("#%.2d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.2d#", d);
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

	printf("\n---------------Unsigned---------------\n\n");

	printf("true : ");
	printf("#%u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%u#", u);
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
	printf("#%x#", x);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%x#", x);
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
	printf("#%X#", X);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%X#", X);
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
	printf("#%p#", &u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%p#", &u);
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
	printf("#%c#", c);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%c#", c);
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

	printf("---------------Chaine--De--Caractere---------------\n\n");

	printf("true : ");
	printf("#%s#", s);
	printf("\n");
	ft_printf("ft_  : ");                     //1
	ft_printf("#%s#", s);
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

	return (0);
}
