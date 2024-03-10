/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxilliaire_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likiffel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:47:34 by likiffel          #+#    #+#             */
/*   Updated: 2024/03/10 23:34:01 by likiffel         ###   ########.fr       */
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
