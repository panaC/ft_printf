/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:56:04 by pierre            #+#    #+#             */
/*   Updated: 2018/03/12 17:19:35 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/includes/libft.h"
#include "../inc/ft_printf.h"
#include "../src/resolve_format.h"

int			ft_vasprintf(char **ret, const char *s, va_list ap)
{
	size_t		size_end;
	va_list		bck;
	char		*str_recurs;
	char		*tmp;
	t_format	*t;
	int			tmp_size;

	if (((size_end = search_next_format(s))) == 0)
	{
		*ret = ft_strdup("");
		return (0);
	}
	t = init_struct();
	*ret = ft_strsub(s, 0, size_end);
	va_copy(t->arg, ap);
	if (!(ft_strrchr(*ret, '%') == (*ret + ft_strlen(*ret) - 1)))
		va_arg(ap, void*);
	va_copy(bck, ap);
	tmp_size = ft_vasprintf(&str_recurs, s + size_end, bck);
	resolve_format(&tmp, *ret, t);
	ft_strdel(ret);
	*ret = ft_strnjoin(tmp, ((t->val_ret > 0) ? (size_t)t->val_ret : 0),
			str_recurs, ((tmp_size > 0) ? (size_t)tmp_size : 0));
	ft_strdel(&str_recurs);
	ft_strdel(&tmp);
	tmp_size += t->val_ret;
	ft_memdel((void**)&t);
	return (tmp_size);
}
