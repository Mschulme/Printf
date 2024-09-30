/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexlower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:03:15 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/18 15:03:15 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_hex(char *array_hex, unsigned int number)
{
	unsigned int	count_num;
	char			*str;

	count_num = ft_check_num(number, 16);
	str = malloc(count_num + 2);
	if (!str)
		return (NULL);
	str[count_num] = '\0';
	if (number == 0)
	{
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	while (count_num--)
	{
		str[count_num] = array_hex[number % 16];
		number /= 16;
	}
	return (str);
}

void	ft_print_hexlower(t_print *tab)
{
	unsigned int	ptr;
	char			*str;

	ptr = va_arg (tab->args, unsigned int);
	str = ft_convert_hex("0123456789abcdef", ptr);
	ft_printszero(tab, str);
	free(str);
}
