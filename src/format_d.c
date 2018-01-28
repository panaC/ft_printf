/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:45:23 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/28 16:17:01 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <stdint.h>
#include "format_d.h"

long long int	cast_format_d(t_format *t)
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

char				*param_precision_d(int precision,
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

char				*param_attribut_d(t_format *t, long long int value,
		char *s)
{
	char		*tmp;
	size_t		sign;

	if (t->attr_0 && t->attr_moins)
		t->attr_0 = FALSE;
	if (t->attr_0 && t->precision > 0)
		t->attr_0 = FALSE;
	if (t->attr_plus && t->attr_space)
		t->attr_space = FALSE;
	sign = ((t->attr_space + t->attr_plus) || value < 0);
	tmp = s;
	if (t->attr_0 && sign)
	{
		if (value < 0)
			s = ft_strjoin("-", fill_length_param(tmp, '0', t->attr_moins, t->length_field - 1));
		else
			s = ft_strjoin((t->attr_plus ? "+" : " "), fill_length_param(tmp, '0', t->attr_moins, t->length_field - 1));
		return (s);
	}
	if (value < 0)
		tmp = ft_strjoin("-", s);
	else if (t->attr_plus)
		tmp = ft_strjoin("+", s);
	s = fill_length_param(tmp, (t->attr_0 ? '0' : ' '), t->attr_moins, t->length_field);
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
	ret = ft_itoa_long(value);
	tmp = param_precision_d(t->precision, value, ret);
	ft_memdel((void**)&ret);
	ret = param_attribut_d(t, value, tmp);
	ft_memdel((void**)&tmp);
	return (ret);
}
