/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:20:48 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/06 14:34:43 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
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
	int				val;

	i = 0;
	if (!s)
		return (ft_strdup("(null)"));
	tmp = ft_strnew(1);
	while (s && s[i] && t->precision)
	{
		val = unicode(&uni, s[i], FALSE);
		t->val_ret = (val < 0) ? -1 : t->val_ret + val;
		ret = ft_strjoin(tmp, uni);
		ft_strdel(&tmp);
		ft_strdel(&uni);
		if (t->precision > 0)
		{
			t->precision -= t->val_ret;
			t->precision = ((t->precision < 0) ? 0 : t->precision);
		}
		tmp = ret;
		i++;
	}
	return (ret);
}

char				*param_attribut_s(t_format *t, char *s)
{
	char			*tmp;

	tmp = fill_length_param(s, (t->attr_0 ? '0' : ' '), t->attr_moins, t->length_field);	
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
	printf(" %p\n", str);
	if (t->op == 'S')
	{
		ret = param_precision_s_unicode(t, str);
	}
	else
	{
		tmp = param_precision_s(t, (char*)str);
		ret = param_attribut_s(t, tmp);
		t->val_ret = ft_strlen(ret);
		ft_strdel(&tmp);
	}
	if (!ret)
		t->val_ret = -1;
	else if (!t->val_ret)
		t->val_ret = ft_strlen(ret);
	return (ret);
}
