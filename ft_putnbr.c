/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiestas <cfiestas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:25:37 by cfiestas          #+#    #+#             */
/*   Updated: 2023/03/12 18:25:39 by cfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include <unistd.h>

int	ft_putnbr(int nbr, char *base, char c)
{
	int	count;
	unsigned int j;
	unsigned int len;

	count = 0;
	len = ft_strlen(base);
	if (nbr < 0)
	{
		if (c != 'u')
			count += ft_putchar('-');
		nbr *= -1;
	}
	j = nbr;
	if (j >= len)
		count += ft_putnbr(j / len, base, c);
	count += ft_putchar(base[j % len]);
	return (count);
}

int ft_putnbr_base(unsigned long int nbr, char *base)
{
	int	count;
	unsigned int	len;

	count = 0;
	len = ft_strlen(base);
	if (nbr >= len)
		count += ft_putnbr_base(nbr/len, base);
	count += ft_putchar(base[nbr % len]);
	return (count);
}

int ft_pointnbr(unsigned long int nbr, char *base)
{
	int i;
	unsigned int j;
	unsigned int len;

	i = 0;
	len = ft_strlen(base);
	j = nbr;
	if (j >= len)
		i += ft_pointnbr(j / len, base);
	i += ft_putchar(base[j % len]);
	return (i);
}

