/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:15:27 by guilhermeur       #+#    #+#             */
/*   Updated: 2024/11/20 14:31:47 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(char especial, va_list args)
{
	int	count;

	count = 0;
	if (especial == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (especial == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (especial == 'p')
		count += ft_print_pointer((unsigned long)va_arg(args, void *));
	else if (especial == 'd' || especial == 'i')
		count += ft_print_digit((va_arg(args, int)), 10);
	else if (especial == 'u')
		count += ft_print_digit_n_negative((va_arg(args, unsigned int)), 10);
	else if (especial == 'x')
		count += ft_print_digit((long)(va_arg(args, unsigned int)), 16);
	else if (especial == 'X')
		count += ft_print_digit_upper((long)(va_arg(args, unsigned int)), 16);
	else if (especial == '%')
		count += ft_print_char('%');
	else
		count += ft_print_char(especial);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	va_start (args, format);
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_print_format(format[i], args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end (args);
	return (count);
}
/* int main()
{
	char *a;
	char *b = "hello world!";
	a = b;

 	//%c Imprime um único caractere.
	ft_printf("Character: %c\n", 'A');
	printf("Character: %c\n", 'A');
	printf("\n");


	//%%s Imprime uma string
	ft_printf("Hello, %s!\n", "World");
	printf("Hello, %s!\n", "World");
	printf("\n");

	//%p O endereço do ponteiro void *
	//deve ser impresso em formato hexadecimal.
	ft_printf("endereco: %p\n", a);
	printf("endereco: %p\n", a);
	printf("\n");


	//%d Imprime um número decimal (base 10).
	ft_printf("Decimal: %d\n", 42);
	printf("Decimal: %d\n", 42);
	printf("\n");

	//%i Imprime um inteiro em base 10.
	ft_printf("Decimal base 10: %i\n", 42);
	printf("Decimal base 10: %i\n", 42);
	printf("\n");

	//%u Imprime um número decimal (base 10) sem sinal.
	ft_printf("Decimal sem sinal: %u\n", 42);
	printf("Decimal sem sinal: %u\n", 42);
	printf("\n");

	//%x Imprime um número em formato hexadecimal (base 16) em minúsculas.
	ft_printf("Hexadecimal (minusculas): %x\n", 600);
	printf("Hexadecimal (minusculas): %x\n", 600);
	printf("\n");

	//%X Imprime um número em formato hexadecimal (base 16) em maiúsculas.
	ft_printf("Hexadecimal (maisculas): %X\n", 42);
	printf("Hexadecimal (maisculas): %X\n", 42);
	printf("\n");

	//%% Imprime um sinal de porcentagem
	ft_printf("sinal de porcentagem: %%\n");
	printf("sinal de porcentagem: %%\n");
	printf("\n");

} */
