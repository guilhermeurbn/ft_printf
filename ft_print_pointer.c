/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:50:06 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/20 14:40:28 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long b)
{
	int	count;

	count = 0;
	if (b == 0)
		return (count += ft_print_str("(nil)"));
	count += ft_print_str("0x");
	count += ft_print_digit(b, 16);
	return (count);
}
