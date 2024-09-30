/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:34:47 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/19 21:35:48 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)str;
	while (n--)
		*ptr++ = c;
	return (str);
}

void	*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;

	ptr = malloc(nb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nb * size);
	return (ptr);
}

int	ft_putchar(char ch)
{
	write(1, &ch, 1);
	return (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
