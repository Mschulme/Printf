/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:03:44 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/18 15:03:44 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(t_print *tab)
{
	char	*str;
	char	nullstr[7];

	str = va_arg(tab->args, char *);
	if (str == NULL)
	{
		nullstr[0] = '(';
		nullstr[1] = 'n';
		nullstr[2] = 'u';
		nullstr[3] = 'l';
		nullstr[4] = 'l';
		nullstr[5] = ')';
		str = nullstr;
	}
	ft_prints(tab, str);
}
