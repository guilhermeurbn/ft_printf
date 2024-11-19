/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit_n_negative.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:50:28 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/19 14:05:16 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_digit_n_negative(long n, int base)
{
	int count;
	char *simbolos;

	count = 0;
	simbolos = "0123456789abcdef";
	if (n < 0)
		n = -n;
	if (n >= base)
		count += print_digit_n_negative(n / base, base);
	count += print_char(simbolos[n % base]);
	return (count);
}
