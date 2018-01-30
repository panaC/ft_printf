/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 09:00:30 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/30 09:52:53 by pleroux          ###   ########.fr       */
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
	if ((t->op == 'u' || t->op == 'o' && t->attr_dieze)
		t->attr_dieze = FALSE;
	if (CONV_OUX && t->attr_space)
		t->attr_space == FALSE;
	if (CONV_OUX && t->attr_plus)
		t->attr_plus = FALSE:
}


