/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:35:58 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/19 13:36:40 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_str(char *str)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	while(*str != '\0')
	{
		count += print_char((int) *str);
		str++;
	}
	return (count);
}
