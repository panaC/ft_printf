/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:18:33 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/24 18:55:25 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include "ft_printf.h"

int		main(void)
{
	char *str;

	va_list		ap;

	ft_vasprintf(&str, "%diro % 0.2dori%d", ap);
	printf("%s", str);
	return 0;
}
