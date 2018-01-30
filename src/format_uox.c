/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_uox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 09:09:36 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/30 13:30:53 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <stdint.h>
#include <stdio.h>
#include "format_uox.h"
#include "format_tools.h"

unsigned long long int	cast_format_uox(t_format *t)
{
	if (t->length_type == code_hh)
		return ((unsigned long long int)(unsigned char)va_arg(t->arg, int));
	if (t->length_type == code_h)
		return ((unsigned long long int)(unsigned short)va_arg(t->arg, int));
	if (t->length_type == code_ll)
		return (va_arg(t->arg, unsigned long long int));
	if (t->length_type == code_l)
		return ((unsigned long long int)va_arg(t->arg, unsigned long int));
	if (t->length_type == code_j)
		return ((unsigned long long int)va_arg(t->arg, uintmax_t));
	if (t->length_type == code_z)
		return ((unsigned long long int)va_arg(t->arg, size_t));
	return ((unsigned long long int)va_arg(t->arg, unsigned int));
}

char					*param_precision_uox(int precision,
		unsigned long long int value, char *s)
{
	char	*str_zero;

	if (value == 0 && precision == 0)
		return (ft_strdup(""));
	return (param_precision(precision, s));
}

char					*param_attribut_uox(t_format *t, char *s)
{
	char				*tmp;

	param_attr(t);
	tmp = s;
	if (t->attr_dieze)
	{
		tmp = ft_strjoin(((t->op == 'x') ? "0x" : "0X"), s);
	}
	s = fill_length_param(tmp,
			(t->attr_0 ? '0' : ' '), t->attr_moins, t->length_field);
	return (s);
}

char					*conv_format_uox(t_format *t)
{
	char					*ret;
	char					*tmp;
	unsigned long long int	value;

	value = cast_format_uox(t);
	/* ici rajouter test Grande lettre length type */
	if (t->op == 'x' || t->op == 'X')
		ret = ft_itoa_base_long(value, ((t->op == 'x') ? BASE_SX : BASE_BX));
	else if (t->op == 'o')
		ret = ft_itoa_base_long(value, BASE_O);
	else
		ret = ft_itoa_base_long(value, BASE_D);
	tmp = param_precision_uox(t->precision, value, ret);
	ft_memdel((void**)&ret);
	ret = param_attribut_uox(t, tmp);
	ft_memdel((void**)&tmp);
	return (ret);
}
