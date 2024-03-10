/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxilliaire_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likiffel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:40:52 by likiffel          #+#    #+#             */
/*   Updated: 2024/03/10 23:32:48 by likiffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		len++;
	}
	if (nb >= 10)
	{
		len += ft_putnbr(nb / 10);
	}
	ft_putchar('0' + nb % 10);
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
