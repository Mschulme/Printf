/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:04:13 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/18 15:04:13 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prints(t_print *tab, char *str)
{
	int		i;
	char	*strmod;

	strmod = malloc(ft_strlen(str) + 1);
	if (!strmod)
		return ;
	i = -1;
	while (str[i++ + 1] != '\0')
		strmod[i] = str[i];
	strmod[i] = 0;
	if (tab -> prc < ft_strlen(strmod) && tab->prc != -1)
		strmod[tab->prc] = 0;
	if (tab->wdt < 0)
	{
		tab->wdt *= -1;
		tab->minus = 1;
	}
	if (ft_strlen(strmod) > tab->wdt)
		tab->wdt = 0;
	else
		tab->wdt -= ft_strlen(strmod);
	ft_printspart2(tab, strmod);
	free(strmod);
}

void	ft_printspart2(t_print *tab, char *strmod)
{
	int	i;

	i = 0;
	if (tab->minus == 0)
	{
		while (tab->wdt > 0)
		{
			(tab->tl) += ft_putchar(' ');
			tab->wdt = tab->wdt - 1;
		}
	}
	while (strmod[i] != '\0')
	{
		(tab -> tl) += ft_putchar(strmod[i]);
		i++;
	}
	if (tab->minus == 1)
	{
		while (tab->wdt > 0)
		{
			(tab->tl) += ft_putchar(' ');
			tab->wdt = tab->wdt - 1;
		}
	}
}
