/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 09:00:30 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/30 13:24:32 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_tools.h"

void			param_attr(t_format *t)
{
	if (t->attr_0 && t->attr_moins)
		t->attr_0 = FALSE;
	if (t->attr_0 && t->precision > 0)
		t->attr_0 = FALSE;
	if (t->attr_plus && t->attr_space)
		t->attr_space = FALSE;
	if ((t->op == 'u' || t->op == 'o' ) && t->attr_dieze)
		t->attr_dieze = FALSE;
	if (CONV_OUX && t->attr_space)
		t->attr_space = FALSE;
	if (CONV_OUX && t->attr_plus)
		t->attr_plus = FALSE;
}

char			*param_precision(int precision, char *s)
{
	char	*str_zero;

	if (precision > 0)
	{
		str_zero = ft_strnew((size_t)precision);
		str_zero = (char *)ft_memset(str_zero, '0',
			(size_t)(precision - ft_strlen(s)));
		str_zero = ft_strcat(str_zero, s);
		return (str_zero);
	}
	return (ft_strdup(s));
}
