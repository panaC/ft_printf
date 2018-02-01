/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:01:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/01 13:59:32 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>
#include "../inc/ft_printf.h"
#include "../src/mae_parse.h"
#include "../src/resolve_format.h"
#include "../src/format_c.h"
#include "../src/format_tools.h"

wint_t				cast_format_c(t_format *t)
{
	if (t->length_type == code_l)
		return (va_arg(t->arg, wint_t));
	return ((wint_t)va_arg(t->arg, int));
}

char				*param_attribut_c(t_format *t, char *s)
{
	char			*tmp;

	//param_attr(t);
	tmp = fill_length_param(s, ' ', t->attr_moins, t->length_field);	
	return (tmp);
}

char				*conv_format_c(t_format *t)
{
	char			*ret;
	char			*tmp;
	wint_t			value;

	if (t->op == 'C')
		t->length_type = code_l;
	value = cast_format_c(t);
	t->val_ret = unicode(&tmp, value);
	ret = param_attribut_c(t, tmp);
	t->val_ret = ((t->length_field > 0) ? t->length_field : t->val_ret);
	ft_memdel((void**)&tmp);
	if (!ret)
		t->val_ret = -1;
	return (ret);
}
