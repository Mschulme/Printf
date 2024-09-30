/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:03:50 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/18 15:03:50 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_unsigned(unsigned int nb, char	*str)
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

void	ft_print_unsigned(t_print *tab)
{
	unsigned int	nb;
	char			*str;

	str = malloc(sizeof(char) * 20);
	if (!str)
		return ;
	nb = va_arg (tab->args, unsigned int);
	str = ft_itoa_unsigned(nb, str);
	ft_printszero(tab, str);
	free(str);
}
