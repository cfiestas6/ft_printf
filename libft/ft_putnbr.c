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

#include <unistd.h>
#include "./libft.h"

int	ft_putnbr(int nb)
{
	char	c;
	unsigned int	i;

	if (nb == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		i += ft_putnbr(147483648);
	}
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
	{
		c = nb + '0';
		i += ft_putchar(c);
	}
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	return (i);
}
