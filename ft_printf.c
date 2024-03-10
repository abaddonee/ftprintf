/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likiffel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:48:19 by likiffel          #+#    #+#             */
/*   Updated: 2024/03/10 22:53:31 by likiffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	after_prct(const char *str, int i, va_list args)
{
	char	letter;
	int		len;

	len = 0;
	letter = str[i];
	if (letter == 'i' || letter == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (letter == 'c' || letter == '%')
	{
		if (letter == '%')
			len = ft_putchar('%');
		else
			len = ft_putchar(va_arg(args, int));
	}
	else if (letter == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (letter == 'u')
		len += ft_putnbr_no_minus(va_arg(args, unsigned int));
	else if (letter == 'x')
		len += ft_itohex_small(va_arg(args, unsigned int));
	else if (letter == 'X')
		len += ft_itohex_big(va_arg(args, unsigned int));
	else if (letter == 'p')
		len += ft_putptr(va_arg(args, void *));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	int		length;

	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			length += after_prct(str, i, args);
		}
		else
		{
			write(1, &str[i], 1);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}
