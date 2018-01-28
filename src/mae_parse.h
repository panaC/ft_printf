/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mae_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:18:51 by pierre            #+#    #+#             */
/*   Updated: 2018/01/28 17:20:09 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAE_PARSE_H
# define __MAE_PARSE_H

#include "../inc/ft_printf.h"

void		mae_attr(char *s, t_format *t);
void		mae_length(char *s, t_format *t);
void		mae_precision(char *s, t_format *t);
void		mae_cast(char *s, t_format *t);
void		mae_parse(char *s, t_format *t);

#endif
