/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:50:18 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/19 13:52:38 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_digit_upper(long n, int base)
{
	int count;
	char *simbolos;

	count = 0;
	simbolos = "0123456789ABCDEF";
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
		count += print_digit_upper(n / base, base);
	count += print_char(simbolos[n % base]);
	return (count);
}
