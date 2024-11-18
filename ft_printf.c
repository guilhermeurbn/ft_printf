/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:15:27 by guilhermeur       #+#    #+#             */
/*   Updated: 2024/11/18 13:48:20 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

static int print_char(int c)
{
	return (write(1, &c, 1));
}

static int print_str(char *str)
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

static int print_digit(long n, int base)
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
	return (count);
}

static int print_digit_n_negative(long n, int base)
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
	return (count);
}

static int print_digit_upper(long n, int base)
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
int print_pointer(unsigned long b)
{
	int count;

	count = 0;
	count += print_str("0x");
	count += print_digit(b, 16);
	return (count);
}
int print_format(char especial, va_list ap)
{
	int count;

	count = 0;
	if (especial == 'c')
		count += print_char(va_arg(ap, int));
	else if (especial == 's')
		count += print_str(va_arg(ap, char *));
	else if (especial == 'p')
		count += print_pointer(va_arg(ap, unsigned long));
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
	printf("Hello, %s!\n", "World");
	printf("\n");

	my_printf("Character: %c\n", 'A');
	printf("Character: %c\n", 'A');
	printf("\n");

	my_printf("Decimal: %d\n", -12345);
	printf("Decimal: %d\n", -12345);

	printf("\n");

	my_printf("Hexadecimal: %x\n", -254);
	printf("Hexadecimal: %x\n", -254);
	printf("\n");

	my_printf("Maisculas_hexa: %X\n", -254);
	printf("Maisculas_hexa: %X\n", -254);
	printf("\n");

	my_printf("sinal de porcentagem: %%\n");
	printf("sinal de porcentagem: %%\n");
	printf("\n");

	char *a;
	char *b;

	a = b;
	my_printf("endereco: %p\n", a);
	printf("endereco: %p\n", a);
	return 0;
}
