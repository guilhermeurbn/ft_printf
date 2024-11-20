/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:48:31 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/20 13:02:06 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(long n, int base)
{
	int		count;
	char	*simbolos;

	count = 0;
	simbolos = "0123456789abcdef";
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
		count += ft_print_digit(n / base, base);
	count += ft_print_char(simbolos[n % base]);
	return (count);
}
