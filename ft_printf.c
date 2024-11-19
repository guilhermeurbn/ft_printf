/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:15:27 by guilhermeur       #+#    #+#             */
/*   Updated: 2024/11/19 14:17:12 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int print_format(char especial, va_list args)
{
	int count;

	count = 0;
	if (especial == 'c')
		count += print_char(va_arg(args, int));
	else if (especial == 's')
		count += print_str(va_arg(args, char *));
	else if (especial == 'p')
		count += print_pointer((unsigned long)va_arg(args, void *));
	else if (especial == 'd' || especial == 'i')
		count += print_digit((va_arg(args, int)), 10);
	else if (especial == 'u')
		count += print_digit_n_negative((va_arg(args, unsigned int)), 10);
	else if (especial == 'x')
		count += print_digit((long)(va_arg(args, unsigned int)), 16);
	else if (especial == 'X')
		count += print_digit_upper((long)(va_arg(args, unsigned int)), 16);
	else if (especial == '%')
		count = print_char('%');
	else
		count += print_char(especial);
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	va_start(args, format);
	count = 0;
	while(format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += print_format(format[i], args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

int main()
{
	ft_printf("Hello, %s!\n", "World");
	printf("Hello, %s!\n", "World");
	printf("\n");

	ft_printf("Character: %c\n", 'A');
	printf("Character: %c\n", 'A');
	printf("\n");

	ft_printf("Decimal: %d\n", -12345);
	printf("Decimal: %d\n", -12345);

	printf("\n");

	ft_printf("Hexadecimal: %x\n", -254);
	printf("Hexadecimal: %x\n", -254);
	printf("\n");

	ft_printf("Maisculas_hexa: %X\n", -254);
	printf("Maisculas_hexa: %X\n", -254);
	printf("\n");

	ft_printf("sinal de porcentagem: %%\n");
	printf("sinal de porcentagem: %%\n");
	printf("\n");

	char *a;
	char *b;

	a = b;
	ft_printf("endereco: %p\n", a);
	printf("endereco: %p\n", a);
	return 0;
}

