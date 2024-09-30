/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:03:55 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/18 15:03:55 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfunction(t_print *tab, const char *format, int pos)
{	
	if (format[pos] == 'd' || format[pos] == 'i')
		ft_print_integer(tab);
	if (format[pos] == 'u')
		ft_print_unsigned(tab);
	if (format[pos] == 'c')
		ft_print_char(tab);
	if (format[pos] == 's')
		ft_print_string(tab);
	if (format[pos] == 'x')
		ft_print_hexlower(tab);
	if (format[pos] == 'X')
		ft_print_hexupper(tab);
	if (format[pos] == 'p')
		ft_print_pointer(tab);
	return (pos);
}

int	ft_eval_helper(t_print *tab, const char *format, int pos)
{
	while (format[pos] >= '0' && format[pos] <= '9')
	{
		(tab->wdt) = 10 * (tab->wdt) + format[pos] - '0';
		pos++;
	}
	if (format[pos] == '.')
	{
		tab->prc = 0;
		pos++;
		if (format[pos] == '*')
			tab->prc = va_arg(tab->args, int);
		while (format[pos] >= '0' && format[pos] <= '9')
		{
			(tab->prc) = 10 * (tab->prc) + format[pos] - '0';
			pos++;
		}
	}
	return (pos);
}

int	ft_eval_format(t_print *tab, const char *format, int pos)
{
	while (format[pos] != 'd' && format[pos] != 'i' && format[pos] != 'u' \
			&& format[pos] != 'c' && format[pos] != 's' && format[pos] != 'x' \
			&& format[pos] != 'X' && format[pos] != 'p')
	{
		pos++;
		while (format[pos] == '0' || format[pos] == '-' || format[pos] == '*')
		{
			if (format[pos] == '0')
				tab->zero = 1;
			if (format[pos] == '-')
				tab->minus = 1;
			if (format[pos] == '*')
				tab->wdt = va_arg(tab->args, int);
			pos++;
		}
		pos = ft_eval_helper(tab, format, pos);
		if (format[pos] == '%')
		{
			ft_print_percent(tab);
			break ;
		}
	}
	return (ft_printfunction(tab, format, pos));
}

void	ft_print(t_print *tab, const char *format)
{
	int	pos;
	int	temp;

	pos = 0;
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			temp = tab->tl;
			ft_initialise_tab(tab);
			tab->tl = temp;
			pos = ft_eval_format(tab, format, pos);
		}
		else
			tab->tl += ft_putchar(format[pos]);
		pos++;
	}
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		res;

	tab = malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	ft_print(tab, format);
	va_end(tab->args);
	res = tab->tl;
	free(tab);
	return (res);
}

/*
int	main(void)
{
	int	i;
	int	j;
	int *ptr;


	i = ft_printf("%d %s %p \n",-55, "test", ptr);
	j = printf("%d %s %p \n",-55, "test", ptr);

	printf("Length ft_printf :%d: \n", i);
	printf("Length printf :%d: \n", j);


	// gcc libftprintf.a -I ft_printf.h test.c -o test
	// %[$][flags][width][.precision]conversion
	// Precision for int: Gives the minimum number of
	//	digits to appear for d, i, u, x, and X conversions
	// '-' flag is left justify
	// No precision for characters
}
*/
