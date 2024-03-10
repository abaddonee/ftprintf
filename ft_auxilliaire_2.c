/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxilliaire_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likiffel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:47:34 by likiffel          #+#    #+#             */
/*   Updated: 2024/03/10 22:48:21 by likiffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itohex_small(unsigned long int nb)
{
	int					len;
	unsigned long int	temp;
	char				result;

	temp = 0;
	len = 0;
	if (nb >= 16)
		len += ft_itohex_small(nb / 16);
	temp = nb % 16;
	if (temp < 10)
		result = '0' + temp;
	else
		result = 'a' + temp - 10;
	ft_putchar(result);
	len++;
	return (len);
}

int	ft_itohex_big(unsigned long int nb)
{
	unsigned long int	temp;
	char				result;
	int					len;

	len = 0;
	temp = 0;
	if (nb >= 16)
		len += ft_itohex_big(nb / 16);
	temp = nb % 16;
	if (temp < 10)
		result = '0' + temp;
	else
		result = 'A' + temp - 10;
	ft_putchar(result);
	len++;
	return (len);
}

int	ft_putptr(void *ptr)
{
	uintptr_t	addresse;
	int			len;

	len = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	addresse = (uintptr_t)ptr;
	ft_putstr("0x");
	len += 2;
	len += ft_itohex_small(addresse);
	return (len);
}

int	ft_putnbr_no_minus(unsigned int nb)
{
	int	len;
	int	result;

	len = 0;
	result = 0;
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		len = 1;
	}
	else
	{
		result = (nb / 10);
		len = ft_putnbr_no_minus(result);
		ft_putchar(nb % 10 + '0');
		len++;
	}
	return (len);
}
