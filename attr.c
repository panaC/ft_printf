/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:37:48 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/26 16:45:54 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <stdint.h>
#include <stdio.h>
#include "ft_printf.h"

char		*fill_length_param(char *s, char car, t_bool is_left, size_t size)
{
	char	*ret;
	char	*tmp;
	size_t	sz;

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

static int main_test_fill_length(void)
{

	char *s = "Hello";

	printf("%s\n", fill_length_param(s, ' ', 1, 1));
	printf("%s\n", fill_length_param(s, ' ', 1, 2));
	printf("%s\n", fill_length_param(s, ' ', 1, 3));
	printf("%s\n", fill_length_param(s, ' ', 1, 4));
	printf("%s\n", fill_length_param(s, ' ', 1, 5));
	printf("%s\n", fill_length_param(s, ' ', 1, 6));
	printf("%s\n", fill_length_param(s, ' ', 1, 7));

	printf("%sa\n", fill_length_param(s, ' ', 0, 1));
	printf("%sa\n", fill_length_param(s, ' ', 0, 2));
	printf("%sa\n", fill_length_param(s, ' ', 0, 3));
	printf("%sa\n", fill_length_param(s, ' ', 0, 4));
	printf("%sa\n", fill_length_param(s, ' ', 0, 5));
	printf("%sa\n", fill_length_param(s, ' ', 0, 6));
	printf("%sa\n", fill_length_param(s, ' ', 0, 7));
	return 0;

}

int		main(void)
{

	main_test_fill_length();
	return 0;
}
