/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiestas <cfiestas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:36:29 by cfiestas          #+#    #+#             */
/*   Updated: 2023/06/12 16:01:25 by cfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	ft_parse(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (write(1, "0x", 2) + ft_putnbr_base(va_arg(args, unsigned long int), "0123456789abcdef"));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int), "0123456789", c));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int), "0123456789", c));
	else if (c == 'u')
		return (ft_pointnbr(va_arg(args, int), "0123456789"));
	else if (c == 'x')
		return (ft_pointnbr(va_arg(args, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_pointnbr(va_arg(args, int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(c));
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int	count;
	int     i;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_strlen(str) > i + 1)
				count += ft_parse(args, str[i + 1]);
			i++;
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main(void)
{
	int i = 0;
	int *p = &i;

	ft_printf("%p", p);
	return (0);
} */
