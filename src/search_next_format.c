/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_next_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:24:59 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/29 14:46:32 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include "../inc/ft_printf.h"

int			search_next_format(const char *s)
{
	int		i;

	i = 0;
	if (!s || s[i] == '\0')
		return (0);
	while (s && s[i] && s[i] != '%')
		i++;
	while (s && s[i] && ft_strchr(STR_FORMAT_CHAR, s[i]) == NULL)
		i++;
	if (s[i] && ft_strchr(STR_FORMAT_CHAR, s[i]))
		i++;
	return (i);
}
