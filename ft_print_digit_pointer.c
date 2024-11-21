/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:53:16 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/21 12:49:07 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit_pointer(unsigned long n, unsigned long base)
{
	int		count;
	char	*ft_base;

	count = 0;
	ft_base = "0123456789abcdef";

	if (n >= base)
		count += ft_print_digit_pointer(n / base, base);
	count += ft_print_char(ft_base[n % base]);
	return (count);
}

