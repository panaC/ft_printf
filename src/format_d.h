/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:18:56 by pierre            #+#    #+#             */
/*   Updated: 2018/01/27 13:22:36 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORMAT_D_H_
# define __FORMAT_D_H_

#include "../inc/ft_printf.h"

long long int	cast_format_d(t_format *t);
char			*param_precision_d(int precision, long long int value, char *s);
char			*param_attribut_d(t_format *t, long long int value, char *s);
char			*conv_format_d(t_format *t);

#endif
