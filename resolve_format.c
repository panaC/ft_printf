/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:56:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/24 17:57:53 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

void		resolve_format(char **ret, char *str, va_list ap)
{
	printf(" %s\n", str);
	*ret = ft_strdup("allo\n");
}
