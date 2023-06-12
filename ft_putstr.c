#include "./libft.h"

int	ft_putstr(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
		i += ft_putchar(*str++);
	return (i);
}
