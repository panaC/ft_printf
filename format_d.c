/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:45:23 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/26 20:07:36 by pleroux          ###   ########.fr       */
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
		return ((long long int)(char)va_arg(t->arg, int));
	if (t->length_type == code_h)
		return ((long long int)(short)va_arg(t->arg, int));
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

	if (t->attr_0 || value < 0)
	{
		tmp = ft_strnew(ft_strlen(s) + 1);
		tmp[0] = (value > 0 ? '+' : '-');
		tmp = ft_strcat(tmp, s);
		if (t->attr_0 && t->precision < 0)
		{
			s = fill_length_param(tmp, '0' ),
				t->attr_moins, t->length_field);
		//ft_memdel((void**)&tmp);
	}
	else
		s = fill_length_param(s, ((t->attr_0 && t->precision < 0) ? '0' : ' '),
			t->attr_moins, t->length_field);
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
	char *s = "520";
	long long int l = -520;
	t_format *t = init_struct();
	char *ret;

	t->precision = -1;
	t->attr_0 = 1;
	t->attr_moins = 1;
	t->length_field = 30;
	ret = param_precision_d(t->precision, l, s);
	ret = param_attribut_d(t, l, ret);
	printf("%sa\n", ret);
	return 0;
}

int				main(void)
{
	test_param_precision();
	return 0;
}
