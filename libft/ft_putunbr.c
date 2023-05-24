#include "./libft.h"

int ft_putunbr(unsigned int n)
{
	int i;

	i = 0;
	if (n < 10)
		 i += ft_putchar(n + '0');
	else
	{
		i += ft_putunbr(n / 10);
		i += ft_putunbr(n % 10);
	}
	return (i);
}
