/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:20:48 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/01 14:13:05 by pleroux          ###   ########.fr       */
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

wint_t				*cast_format_s(t_format *t)
{
	if (t->length_type == code_l)
		return ((wint_t*)va_arg(t->arg, wchar_t*));
	return ((wint_t*)va_arg(t->arg, char*));
}

char				*param_precision_s(t_format *t, char *s)
{
	int				i;
	char			*ret;

	i = 0;
	if (!s)
		ret = ft_strdup("(null)");
	else
		ret = ft_strdup(s);
	while (ret && ret[i] && t->precision)
	{
		t->precision--;
		i++;
	}
	if (ret)
		ret[i] = '\0';
//	t->val_ret = i;
	return (ret);
}

char			*param_precision_s_unicode(t_format *t, wint_t *s)
{
	int				i;
	char			*tmp;
	char			*ret;
	char			*uni;

	i = 0;
	tmp = ft_strnew(1);
	if (!s)
		return (ft_strdup("(null)"));
	while (s && s[i] && t->precision)
	{
		t->val_ret = ((unicode(&uni, s[i]) < 0) ? -1 :
				t->val_ret + unicode(&uni, s[i]));
		ret = ft_strjoin(tmp, uni);
		if (t->precision > 0)
		{
			t->precision -= t->val_ret;
			t->precision = ((t->precision < 0) ? 0 : t->precision);
		}
		ft_memdel((void**)&tmp);
		ft_memdel((void**)&uni);
		tmp = ret;
		i++;
	}
	return (ret);
}

char				*param_attribut_s(t_format *t, char *s)
{
	char			*tmp;

	//param_attr(t);
	tmp = fill_length_param(s, ' ', t->attr_moins, t->length_field);	
	return (tmp);
}


char				*conv_format_s(t_format *t)
{
	char			*ret;
	char			*tmp;
	wint_t			*str;

	if (t->op == 'S')
		t->length_type = code_l;
	str = cast_format_s(t);
	if (t->op == 'S')
		tmp = param_precision_s_unicode(t, str);
	else
		tmp = param_precision_s(t, (char*)str);
	ret = param_attribut_s(t, tmp);
	ft_memdel((void**)&tmp);
	if (!ret)
		t->val_ret = -1;
	else
		t->val_ret = ft_strlen(ret);
	return (ret);
}
