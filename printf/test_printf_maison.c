#include "ft_printf.h"

#include <limits.h>

//int		ft_printf(const char *str, ...) __attribute__ ((format (printf, 1, 2)));

#define mac(s) b(s)
#define b(s) #s
#define test(arg) printf ("\n--------------TEST DE |"mac(arg)" + specifier| ----------------\n"); \
	printf("n : |1 3 5 7 9 B D F\n");\
	val = printf(mac(p : |%)mac(arg)mac(p| ), p);\
	printf(mac(\tval : %d\n), val);\
    val = ft_printf(mac(p : |%)mac(arg)mac(p| ), p);\
	printf(mac(\tval : %d\n), val);\
	val = printf(mac(c : |%)mac(arg)mac(c| ), c);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(c : |%)mac(arg)mac(c| ), c);\
	ft_printf(mac(\tval : %d\n), val);\
	val = printf(mac(s : |%)mac(arg)mac(s| ), s);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(s : |%)mac(arg)mac(s| ), s);\
	printf(mac(\tval : %d\n), val);\
	val = printf(mac(d : |%)mac(arg)mac(d| ), d);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(d : |%)mac(arg)mac(d| ), d);\
	printf(mac(\tval : %d\n), val);\
	val = printf(mac(i : |%)mac(arg)mac(i| ), i);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(i : |%)mac(arg)mac(i| ), i);\
	printf(mac(\tval : %d\n), val);\
	val = printf(mac(u : |%)mac(arg)mac(u| ), u);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(u : |%)mac(arg)mac(u| ), u);\
	printf(mac(\tval : %d\n), val);\
	val = printf(mac(x : |%)mac(arg)mac(x| ), x);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(x : |%)mac(arg)mac(x| ), x);\
	printf(mac(\tval : %d\n), val);\
	val = printf(mac(X : |%)mac(arg)mac(X| ), X);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(X : |%)mac(arg)mac(X| ), X);\
	printf(mac(\tval : %d\n), val);\
	printf("n : | 2 4 6 8 A C E \n");


#define testw(arg) printf("\n--------------TEST DE |"mac(arg)" + specifier avec * = "mac(WILDCARD)" | ----------------\n\n"); \
	printf("n : |1 3 5 7 9 B D F\n");\
	val = printf(mac(p : |%)mac(arg)mac(p| ), WILDCARD,p);\
	printf(mac(\tval : %d\n), val);\
    val = ft_printf(mac(p : |%)mac(arg)mac(p| ), WILDCARD, p);\
	printf(mac(\tval : %d\n\n), val);\
 	val = printf(mac(c : |%)mac(arg)mac(c| ), WILDCARD, c);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(c : |%)mac(arg)mac(c| ),WILDCARD, c);\
	ft_printf(mac(\tval : %d\n\n), val);\
	val = printf(mac(s : |%)mac(arg)mac(s| ), WILDCARD, s);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(s : |%)mac(arg)mac(s| ), WILDCARD, s);\
	printf(mac(\tval : %d\n\n), val);\
	val = printf(mac(d : |%)mac(arg)mac(d| ), WILDCARD, d);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(d : |%)mac(arg)mac(d| ), WILDCARD, d);\
	printf(mac(\tval : %d\n\n), val);\
	val = printf(mac(i : |%)mac(arg)mac(i| ), WILDCARD, i);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(i : |%)mac(arg)mac(i| ), WILDCARD, i);\
	printf(mac(\tval : %d\n\n), val);\
	val = printf(mac(u : |%)mac(arg)mac(u| ), WILDCARD, u);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(u : |%)mac(arg)mac(u| ), WILDCARD, u);\
	printf(mac(\tval : %d\n\n), val);\
	val = printf(mac(x : |%)mac(arg)mac(x| ), WILDCARD, x);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(x : |%)mac(arg)mac(x| ), WILDCARD, x);\
	printf(mac(\tval : %d\n\n), val);\
	val = printf(mac(X : |%)mac(arg)mac(X| ), WILDCARD, X);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(X : |%)mac(arg)mac(X| ), WILDCARD, X);\
	printf(mac(\tval : %d\n), val);\
	val = printf(mac(perc : |%)mac(arg)mac(%| ), WILDCARD);\
	printf(mac(\tval : %d\n), val);\
	val = ft_printf(mac(perc : |%)mac(arg)mac(%| ), WILDCARD);\
	ft_printf(mac(\tval : %d\n\n), val);\
	printf("n : |1 3 5 7 9 B D F\n");\


int		main(void)
{
	// Tests de Luis
	int test = 1;
	char c = 'c';
	char *n = NULL;
	char *p = (char*)malloc(sizeof(char)) + 0xffffffffffff;
	char *s = malloc(10);
	s = 0; //"Bonjour !";
	int d = 55;
	int i = -10;
	unsigned int u = 250;
	unsigned int x = 16 * 11 + 2;
	unsigned int X = 16 * 15 + 8;
	int val;

#ifndef WILDCARD
# define WILDCARD 0
#endif


	testw(*.)
	(void)c;
	(void)s;
	(void)p;
	(void)d;
	(void)i;
	(void)u;
	(void)x;
	(void)X;
	(void)val;
	
	return (0);
}
