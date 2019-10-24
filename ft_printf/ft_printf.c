
#include <stdarg.h>
#include <unistd.h>

int    ft_flags(const char *str, int *ptr_i, va_list ap)
{
    int compt;
    int i;

    i = *ptr_i;
    compt = 0;
    /*if (test_flags(str[i])
        compt = ft_flags(str + i + 1, ptr_i, ap);
    else if (test_width(str[i])
        compt = ft_width(str + i + 1, ptr_i, ap);
    else if (test_precision(str[i])
        compt = ft_precis(str + i + 1, ptr_i, ap);
    else if (test_specifier(str[i])
        compt = ft_specifier(str[i]);*/
    /*else */if (str[i] == '%')
    {
        compt = 1;
        write(1, "%", 1);
        *ptr_i += 1;
    }
    /*else if (str[i] == 0)
        compt = ft_end();
    else
        compt = ft_unk_conv()*/
   return (compt);
}

int     ft_printf(const char *str, ...)
{
    int i;
    int compt;
    va_list ap;

    va_start(ap, str);
    i = 0;
    compt = 0;
    while (str[i])
    {
        if (str[i]== '%')
        {
            i++;
            compt += ft_flags(str, &i, ap);
        }
        else
        {
            write(1, str + i, 1);
            i++;
            compt++;
        }
    }
    return (compt);
}
