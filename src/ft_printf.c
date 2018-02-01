/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:37:01 by pierre            #+#    #+#             */
/*   Updated: 2018/02/01 13:29:55 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <libft.h>
#include "../inc/ft_printf.h"

int				ft_printf(const char *s, ...)
{
	char		*str;
	va_list		ap;
	static int	size;

	va_start(ap, s);
	if (size < 0)
		ft_vasprintf(&str, s, ap);
	else
		size = ft_vasprintf(&str, s, ap);
	va_end(ap);
	write(1, str, size);
	return (size);
}
