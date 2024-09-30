/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:04:26 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/18 15:04:26 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	ft_check_num(unsigned long long number, int size)
{
	int	count;

	count = 0;
	while (number > 0)
	{
		number /= size;
		count++;
	}
	return (count);
}

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = -1;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->zero = 0;
	tab->minus = 0;
	tab->percentage = 0;
	tab->sp = 0;
	tab->asterisk = 0;
	tab->negative = 0;
	return (tab);
}
