/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:37:01 by pierre            #+#    #+#             */
/*   Updated: 2018/01/31 11:42:22 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <libft.h>
#include "../inc/ft_printf.h"

int				ft_printf(const char *s, ...)
{
	char		*str;
	va_list		ap;
	int			size;

	va_start(ap, s);
	size = ft_vasprintf(&str, s, ap);
	va_end(ap);
	ft_putstr(str);
	return (size);
}
