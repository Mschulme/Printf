/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:03:38 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/18 15:03:38 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_pointer(char *array_hex, unsigned long number)
{
	int		size_hex;
	int		count_num;
	char	*str;

	size_hex = ft_strlen(array_hex);
	count_num = ft_check_num(number, size_hex);
	str = malloc(count_num + 6);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[count_num + 2] = '\0';
	while (count_num-- > 0)
	{
		str[count_num + 2] = array_hex[number % size_hex];
		number /= size_hex;
	}
	if (count_num == 0)
		str[count_num + 2] = array_hex[number % size_hex];
	return (str);
}

void	ft_print_pointer(t_print *tab)
{
	unsigned long	ptr;
	char			*str;
	char			nil[4];

	ptr = va_arg (tab->args, unsigned long);
	str = ft_convert_pointer("0123456789abcdef", ptr);
	if (ptr == 0)
	{
		nil[0] = '0';
		nil[1] = 'x';
		nil[2] = '0';
		nil[3] = 0;
		ft_prints(tab, nil);
	}
	else
		ft_prints(tab, str);
	free(str);
}
