/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_n_negative.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:50:28 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/20 12:23:57 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit_n_negative(long n, int base)
{
	int		count;
	char	*simbolos;

	count = 0;
	simbolos = "0123456789abcdef";
	if (n < 0)
		n = -n;
	if (n >= base)
		count += ft_print_digit_n_negative(n / base, base);
	count += ft_print_char(simbolos[n % base]);
	return (count);
}
