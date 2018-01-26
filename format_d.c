/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:45:23 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/26 17:14:42 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <stdint.h>
#include <stdio.h>
#include "ft_printf.h"

static long long int	cast_format_d(t_format *t)
{
	if (t->length_type == code_hh)
		return ((long long int)va_arg(t->arg, char));
	if (t->length_type == code_h)
		return ((long long int)va_arg(t->arg, short));
	if (t->length_type == code_ll)
		return ((long long int)va_arg(t->arg, long int));
	if (t->length_type == code_l)
		return (va_arg(t->arg, long long int));
	if (t->length_type == code_j)
		return ((long long int)va_arg(t->arg, intmax_t));
	if (t->length_type == code_z)
		return ((long long int)va_arg(t->arg, size_t));
	return ((long long int)va_arg(t->arg, int));
}

static char				*param_precision_d(int precision,
		long long int value, char *s)
{
	char	*str_zero;

	if (value == 0 && precision == 0)
		return (ft_strdup(""));
	if (precision <= (int)ft_strlen(s))
		return (ft_strdup(s)); /* Ne rien faire */
	str_zero = ft_strnew((size_t)precision);
	str_zero = (char *)ft_memset(str_zero, '0',
			(size_t)(precision - ft_strlen(s)));
	str_zero = ft_strcat(str_zero, s);
	return (str_zero);
}

static char				*param_attribut_d(t_format *t, long long int value,
		char *s)
{
	char	*tmp;

	tmp = s;
	if (value > 0 && t->attr_plus)
	{
		tmp = ft_strnew(ft_strlen(tmp) + 1);
		tmp[0] = '+';
		tmp = ft_strcat(tmp, s);
		ft_memdel((void**)&tmp);
	}
	s = fill_length_param(tmp, ((t->attr_0 && t->precision < 0) ? '0' : ' '),
			t->attr_moins, ft_strlen(tmp));
	ft_memdel((void**)&tmp);
	return (s);
}

char					*conv_format_d(t_format *t)
{
	char			*ret;
	char			*tmp;
	long long int	value;

	if (t->op == 'D')
		t->length_type = code_l;
	value = cast_format_d(t);
	//ret = ft_itoa_long(value);
	ret = NULL; //debug
	tmp = param_precision_d(t->precision, value, ret);
	ft_memdel((void**)&ret);
	ret = param_attribut_d(t, value, tmp);
	ft_memdel((void**)&tmp);
	return (ret);
}

int						test_param_precision()
{
	char *s = "123456789";
	long long int l = 123456789;

	printf("%s\n", param_precision_d(20, l, s));

	return 0;
}

int				main(void)
{
	test_param_precision();
	return 0;
}
