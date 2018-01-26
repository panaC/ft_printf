/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:08:44 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/26 11:19:01 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include "ft_printf.h"

t_format		*init_struct(void)
{
	t_format	*ret;

	if ((ret = (t_format*)ft_memalloc(sizeof(*ret))))
		return (NULL);
	attr_dieze = FALSE;
	attr_0 = FALSE;
	attr_- = FALSE;
	attr_+ = FALSE;
	attr_space = FALSE;
	ret->length_field = -1;
	ret->precision = -1;
	ret->length_type = code_none;
	ret->conv_indicator = -1;
	return (ret);
}
