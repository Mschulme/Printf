/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:04:05 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/18 15:04:05 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		prc;
	int		pnt;
	int		minus;
	int		tl;
	int		sign;
	int		zero;
	int		percentage;
	int		sp;
	int		asterisk;
	int		negative;
}	t_print;

int		ft_printf(const char *format, ...);
void	print(const char *format, t_print *tab);
int		ft_eval_format(t_print *tab, const char *format, int pos);
int		ft_eval_helper(t_print *tab, const char *format, int pos);
int		ft_printfunction(t_print *tab, const char *format, int pos);

void	ft_print_percent(t_print *tab);

void	ft_print_char(t_print *tab);
void	ft_handle_left_align(t_print *tab);
void	ft_handle_right_align(t_print *tab);

void	ft_print_string(t_print *tab);

void	ft_print_integer(t_print *tab);
char	*ft_itoa(int nb, char	*str);
char	*ft_numtostring(long nb, int i, int j, char *str);

void	ft_print_unsigned(t_print *tab);
char	*ft_itoa_unsigned(unsigned int nb, char	*str);

void	ft_print_hexlower(t_print *tab);
char	*ft_convert_hex(char *array_hex, unsigned int number);

void	ft_print_hexupper(t_print *tab);
char	*ft_convert_hex_upper(char *array_hex, unsigned int number);

void	ft_print_pointer(t_print *tab);
char	*ft_convert_pointer(char *array_hex, unsigned long number);

void	ft_prints(t_print *tab, char *str);
void	ft_printspart2(t_print *tab, char *strmod);

void	ft_printszero(t_print *tab, char *strmod);
int		ft_printzeropart1(t_print *tab, char *str, char *strmod);
void	ft_printzeropart2(t_print *tab, char *str, char *strmod, int cal);

int		ft_abs(int num);
int		ft_max(int num1, int num2);
int		ft_check_num(unsigned long long number, int size);
t_print	*ft_initialise_tab(t_print *tab);

int		ft_putchar(char ch);
int		ft_strlen(const char *s);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_calloc(size_t nb, size_t size);

#endif