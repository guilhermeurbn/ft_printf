/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_upper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:50:18 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/20 12:20:34 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit_upper(long n, int base)
{
	int		count;
	char	*simbolos;

	count = 0;
	simbolos = "0123456789ABCDEF";
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
		count += ft_print_digit_upper(n / base, base);
	count += ft_print_char(simbolos[n % base]);
	return (count);
}
