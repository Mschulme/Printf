/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:03:33 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/18 15:03:33 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_numtostring(long nb, int i, int j, char *str)
{
	char	temp;

	if (nb < 0)
	{
		str[0] = '-';
		i = 1;
		j = 1;
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i] = (nb % 10 + '0');
		nb = nb / 10;
		i++;
	}
	str[i] = '\0';
	while (i >= j + 1)
	{
		temp = str[i - 1];
		str[i - 1] = str[j];
		str[j] = temp;
		i--;
		j++;
	}
	return (str);
}

char	*ft_itoa(int nb, char *str)
{
	int		i;
	int		j;
	long	h;

	h = nb;
	i = 0;
	j = 0;
	if (nb == 0)
	{
			str[0] = '0';
			str[1] = '\0';
	}
	else
		str = ft_numtostring(h, i, j, str);
	return (str);
}

void	ft_print_integer(t_print *tab)
{
	long	nb;
	char	*str;

	str = malloc(sizeof(char) * 20);
	if (!str)
		return ;
	nb = va_arg(tab->args, int);
	str = ft_itoa(nb, str);
	ft_printszero(tab, str);
	free(str);
}
