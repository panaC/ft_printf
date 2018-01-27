/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:37:48 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/27 12:53:59 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <stdint.h>
#include <stdio.h>
#include "../inc/ft_printf.h"

char		*fill_length_param(char *s, char car, t_bool is_left, size_t size)
{
	char	*ret;
	char	*tmp;
	size_t	sz;

	if (s == NULL)
		return (ft_strdup(""));
	sz = size - ft_strlen(s);
	if ((int)(sz) <= 0)
		return (ft_strdup(s));
	tmp = ft_strnew(sz);
	tmp = (char*)ft_memset(tmp, car, sz);
	if (is_left)
		ret = ft_strjoin(tmp, s);
	else
		ret = ft_strjoin(s, tmp);
	ft_memdel((void**)&tmp);
	return (ret);
}
