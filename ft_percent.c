/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:16:18 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/27 17:20:48 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_print *tab)
{
	if (tab->wdt < 0)
	{
		tab->wdt *= -1;
		tab -> minus = 1;
	}
	if ((tab->zero || tab->wdt) && !tab->minus)
		ft_handle_left_align(tab);
	tab->tl += ft_putchar('%');
	if (tab->wdt && tab->minus)
		ft_handle_right_align(tab);
}
