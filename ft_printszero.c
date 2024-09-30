/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printszero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:04:21 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/18 15:04:21 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printszero(t_print *tab, char *strmod)
{
	int		cal;
	char	*str;

	if (strmod[0] == '-')
		tab->prc += 1;
	cal = ft_max(ft_max(ft_strlen(strmod), ft_abs(tab->wdt)), tab->prc);
	str = ft_calloc(cal + 3, sizeof(int));
	str = ft_memset(str, ' ', cal);
	tab -> tl += cal;
	if (strmod[0] == '0' && tab->prc >= 0)
		strmod[0] = '\0';
	if (strmod[0] == '\0' && tab->wdt == 0 && tab->prc == 0)
		tab->tl -= 1;
	else
	{
		ft_printzeropart1(tab, str, strmod);
		if (tab->wdt >= 0 && tab->minus == 0)
			ft_printzeropart2(tab, str, strmod, cal);
	}
	free(str);
}

int	ft_printzeropart1(t_print *tab, char *str, char *strmod)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (tab->wdt < 0 || tab->minus == 1)
	{
		if (strmod[0] == '-')
		{
			str[i++] = '-';
			j++;
		}
		while (tab->prc-- > ft_strlen(strmod))
			str[i++] = '0';
		while (strmod[j] != '\0')
			str[i++] = strmod[j++];
		while (*str != '\0')
			ft_putchar(*str++);
	}
	return (i);
}

void	ft_printzeropart2(t_print *tab, char *str, char *strmod, int cal)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strlen(strmod) >= j && strmod[ft_strlen(strmod) - j] != '-')
		str[cal - i++] = strmod[ft_strlen(strmod) - j++];
	while (tab->prc > ft_strlen(strmod))
	{
		str[cal - i++] = '0';
		tab->prc -= 1;
	}
	if ((tab -> prc < 0 || (strmod[0] == '-' && tab->prc < 1)) \
		&& tab->zero == 1)
	{
		while (cal - i >= 0)
			str[cal - i++] = '0';
		if (strmod[0] == '-')
			str[0] = '-';
	}
	if (strmod[0] == '-')
		str[cal - i] = '-';
	while (*str != '\0')
		ft_putchar(*str++);
}
