#include <stdarg.h>
#include <unistd.h>
#include<stdio.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}
int ft_decilen(int x)
{
    int len = 0;
    if(x == 0)
        return 1;
    if (x < 0)
    {
        len++;
        x = -x;
    }
    while(x != 0)
    {
        len++;
        x /= 10;
    }
    return len;
}
int ft_putnbr(int x)
{
    int i = ft_decilen(x);
    if(x == -2147483648)
    {
        write(1, "-2147483648", 11);
        return 11;
    }
    if(x < 0)
    {
        ft_putchar('-');
        x = -x;
    }
    if(x > 9)
    {
        ft_putnbr(x / 10);
        ft_putnbr(x % 10);
    }
    if(x <= 9)
        ft_putchar(x + '0');
    return i;
}
int ft_hexlen(unsigned int x)
{
    int len = 0;
    if(x == 0)
        return 1;
    while(x != 0)
    {
        len++;
        x /= 16;
    }
    return len;
}
int ft_puthex(unsigned int x)
{
    int i = ft_hexlen(x);
    if(x >= 16)
    {
        ft_puthex(x / 16);
        x %= 16;
    }
    if(x <= 9)
        ft_putchar(x + '0');
    else
        ft_putchar(x - 10 + 'a');
    return i;
}
int ft_printstr(char *str)
{
    int i = 0;

    if(!str)
        str = "(null)";
    while(str[i])
    {
        write(1,&str[i], 1);
        i++;
    }
    return i;
}

int ft_format(va_list arg, char c)
{
    int len = 0;

    if(c == 's')
        len += ft_printstr(va_arg(arg,char *));
    if(c == 'd')
        len += ft_putnbr(va_arg(arg,int));
    if(c == 'x')
        len += ft_puthex(va_arg(arg,unsigned int));
}

int ft_printf(const char *str,...)
{
    int len;
    int i;
    va_list arg;

    i = 0;
    len = 0;

    va_start(arg,str);

    while(str[i])
    {
        if(str[i] == '%')
        {
            len += ft_format(arg,str[i + 1]);
            i++;
        }
        else
            len += write(1,&str[i], 1);
        i++;
    }
    va_end(arg);
    return (len);
}

int main()
{
 int i =  ft_printf("%d\n", -2147483648);
 int j = printf("%d\n", -2147483648);
 printf("%d %d\n", i, j);
 i =  ft_printf("%d\n", -50);
 j = printf("%d\n", -50);
 printf("%d %d\n", i, j);
 i =  ft_printf("%d\n", 50);
 j = printf("%d\n", 50);
 printf("%d %d\n", i, j);
 i = ft_printf("%x\n", 42);
 j = printf("%x\n", 42);
 printf("%d %d\n", i, j);
 i = ft_printf("%s\n", NULL);
 j = printf("%s\n", NULL);
 printf("%d %d\n", i, j);
  i = ft_printf("%x\n", 0);
 j = printf("%x\n", 0);
 printf("%d %d\n", i, j);
 i =  ft_printf("%d\n", 0);
 j = printf("%d\n", 0);
 printf("%d %d\n", i, j);
 i = ft_printf("%x\n", 42);
 j = printf("%x\n", 42);
 printf("%d %d\n", i, j);

}