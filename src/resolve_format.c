/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:56:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/01 13:50:27 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <stdio.h>
#include "../inc/ft_printf.h"
#include "../src/format_d.h"
#include "../src/mae_parse.h"
#include "../src/format_uox.h"
#include "../src/resolve_format.h"
#include "../src/format_c.h"
#include "../src/format_s.h"
#include "../src/format_tools.h"

char		*conv_format_p(t_format *t)
{
	t->attr_dieze = TRUE;
	t->length_type = code_l;
	t->op = 'x';
	t->flag_pc = TRUE;
	return(conv_format_uox(t));
}

char		*conv_format_pc(t_format *t)
{
	char			*ret;
	char			*tmp;

	tmp = ft_strdup("%");
	ret = fill_length_param(tmp, (t->attr_0 ? '0' : ' '), t->attr_moins,
			t->length_field);
	ft_memdel((void**)&tmp);
	if (!ret)
		t->val_ret = -1;
	else
		t->val_ret = ft_strlen(ret);
	return (ret);
}

char		*mae_format(char *s, t_format *t)
{
	char		*ret;
	t_format	tmp;

	if (s || *s)
	{
		t->op = *s;
		if (*s == 'd' || *s == 'D' || *s == 'i')
			return (conv_format_d(t));
		else if (*s == 's' || *s == 'S')
			return (conv_format_s(t));
		else if (*s == 'p')
			return (conv_format_p(t));
		else if (*s == 'o' || *s == 'O' || *s == 'u' || *s == 'U' ||
				*s == 'x' || *s == 'X')
			return(conv_format_uox(t));
		else if (*s == 'c' || *s == 'C')
			return (conv_format_c(t));
		else if (*s == '%')
			return (conv_format_pc(t));
	}
	t->val_ret = -1;
	return (NULL);
}

void		resolve_format(char **ret, char *str, t_format *t)
{
	char	*s;
	char	*tmp;

	s = str;
	*ret = NULL;
	while (str && *str && *str != '%')
		str++;
	if (str && *str == '%')
	{
		if (!((tmp = mae_format(mae_parse(str + 1, t), t))))
			*ret = ft_strdup("");
		else
		{
			*str = '\0';
			*ret = ft_strnjoin(s, ft_strlen(s), tmp,
					((t->val_ret > 0) ? (size_t)t->val_ret : 0));
			ft_memdel((void**)&tmp);
		}
	}
	else if (str && *str == '\0')
		*ret = ft_strdup(s);
	t->val_ret += ft_strlen(s);
}
