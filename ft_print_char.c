/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:03:20 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/18 15:03:20 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_left_align(t_print *tab)
{
	while (tab->wdt-- > 1)
	{
		if (tab->zero)
			tab->tl += ft_putchar('0');
		else
			tab->tl += ft_putchar(' ');
	}
}

void	ft_handle_right_align(t_print *tab)
{
	while (tab->wdt-- > 1)
		tab->tl += ft_putchar(' ');
}

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	if (tab->wdt < 0)
	{
		tab->wdt *= -1;
		tab -> minus = 1;
	}
	if ((tab->zero || tab->wdt) && !tab->minus)
		ft_handle_left_align(tab);
	tab->tl += ft_putchar(c);
	if (tab->wdt && tab->minus)
		ft_handle_right_align(tab);
}
