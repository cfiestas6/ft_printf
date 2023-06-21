/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiestas <cfiestas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:38:13 by cfiestas          #+#    #+#             */
/*   Updated: 2023/06/07 13:15:23 by cfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_strlen(const char *str);
int	ft_putnbr(int nbr, char *base, char c);
int ft_putnbr_base(unsigned long int nbr, char *base);
int ft_pointnbr(unsigned long int nbr, char *base);
int	ft_putchar(const char c);
int	ft_putstr(const char *str);

#endif
