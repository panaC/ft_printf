/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:56:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/28 18:50:51 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <stdio.h>
#include "../inc/ft_printf.h"

char*		mae_format(char *s, t_format *t)
{
	if (s || *s)
	{
		t->op = *s;
		if (*s == 'd' || *s == 'D' || *s == 'i')
			return (conv_format_d(t));
		else if (*s == 's' || *s == 'S')
			printf("Not supported\n");
		else if (*s == 'p')
			printf("Not supported\n");
		else if (*s == 'O' || *s == 'u' || *s == 'U' || *s == 'x' || *s == 'X')
			printf("Not supported\n");
		else if (*s == 'c' || *s == 'C')
			printf("Not supported\n");
	}
	return (NULL);
}

void		resolve_format(char **ret, char *str, t_format *t)
{
	char	*s;
	char	*tmp

	s = str;
	*ret = NULL;
	while (str && *str && *str != '%')
		str++;
	if (str && *str == '%')
	{
		if (!((tmp = mae_format(mae_parse(str + 1, t), t))))
			*ret = ft_strdup("");
		else
		{
			*str = '\0';
			*ret = ft_strjoin(s, tmp);
			ft_memdel((void**)&tmp);
		}
	}
	else if (str && *str == '\0')
		*ret = ft_strdup(str);
}
