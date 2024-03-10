/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likiffel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:16:10 by likiffel          #+#    #+#             */
/*   Updated: 2024/03/10 23:33:08 by likiffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h> 

int		ft_putptr(void *ptr);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		int_len(int nb);
int		ft_putstr(char *str);
int		ft_itohex_small(unsigned long int nb);
int		ft_itohex_big(unsigned long int nb);
int		ft_putnbr_no_minus(unsigned int nb);
int		after_prct(const char *str, int i, va_list args);
int		ft_printf(const char *str, ...);

#endif
