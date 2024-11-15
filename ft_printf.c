/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:15:27 by guilhermeur       #+#    #+#             */
/*   Updated: 2024/11/15 16:04:44 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int print_char(int c)
{
	return (write(1, &c, 1));
}

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

int print_digit(long n, int base)
{
	int count;
	char *simbolos;

	count = 0;
	simbolos = "0123456789abcdef";
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
		count += print_digit(n / base, base);
	count += print_char(simbolos[n % base]);
	return count;
}

int print_digit_n_negative(long n, int base)
{
	int count;
	char *simbolos;

	count = 0;
	simbolos = "0123456789abcdef";
	if (n < 0)
		n = -n;
	if (n >= base)
		count += print_digit(n / base, base);
	count += print_char(simbolos[n % base]);
	return count;
}

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
		count += print_digit(n / base, base);
	count += print_char(simbolos[n % base]);
	return count;
}

int print_format(char especial, va_list ap)
{
	int count;

	count = 0;
	if (especial == 'c')
		count += print_char(va_arg(ap, int));
	else if (especial == 's')
		count += print_str(va_arg(ap, char *));
	/* else if (especial == 'p')
		count += print_pointer(va_arg(ap, char *)); */
	else if (especial == 'd')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (especial == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (especial == 'u')
		count += print_digit_n_negative((long)(va_arg(ap, int)), 10);
	else if (especial == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16);
	else if (especial == 'X')
		count += print_digit_upper((long)(va_arg(ap, unsigned int)), 16);
	else if (especial == '%')
		count += print_char('%');
	else
		count += print_char(especial);
	return (count);
}

int my_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while(*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += print_format(*format, ap);

		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
int main()
{
	my_printf("Hello, %s!\n", "World");
	my_printf("Character: %c\n", 'A');
	my_printf("Decimal: %d\n", -12345);
	my_printf("Hexadecimal: %x\n", 255);
	return 0;
}
