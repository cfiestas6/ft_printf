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
#include <stdarg.h>
#include <stddef.h>

static int	ft_parse(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putstr("0x") + ft_putnbr_base(va_arg(args, unsigned long int), "0123456789abcdef"));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int), "0123456789", c));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int), "0123456789", c));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!str)
		return (0);
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
}*/
