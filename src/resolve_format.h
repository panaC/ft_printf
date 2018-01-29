/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_format.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:09:22 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/29 10:34:36 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RESOLVE_FORMAT_
# define __RESOLVE_FORMAT_
# include "../inc/ft_printf.h"

char*		mae_format(char *s, t_format *t);
void		resolve_format(char **ret, char *str, t_format *t);

#endif
