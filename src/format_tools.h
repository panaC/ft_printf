/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 08:59:30 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/30 09:51:13 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FORMAT_TOOLS_H
# define _FORMAT_TOOLS_H
# include "../inc/ft_printf.h"
# define CONV_OUX (t->op == 'x' || t->op == 'X' || t->op == 'o' || t->op == 'u')

void			param_attr(t_format *t);

#endif
