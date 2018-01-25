/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:45:23 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/25 18:29:13 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <stdio.h>
#include "ft_printf.h"

char				*param_format_d(char *s, t_format *t)
{
	char			*ret;

	`
	return (ret);
}

char				*conv_format_d(t_format *t);
{
	char			*ret;
	long long int	value;

	if (t->conv_indicator == 'D')
		t->length_type = code_l;
	value = cast_format_d(t_format *t);
	ret = ft_itoa_long(value);
	ret = param_format_d(ret, t);
	return (ret);
}
