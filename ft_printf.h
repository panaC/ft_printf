/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:19:26 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/25 17:45:00 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_
#define __FT_PRINTF_

#include <stdarg.h>

#define STR_FORMAT_CHAR "sSpdDioOuUxXcC"

typedef enum				e_length
{
	code_none = 1,
	code_hh,
	code_h,
	code_l,
	code_ll,
	code_j,
	code_z
}							t_length;

typedef struct			s_format
{
	char				attribut[5];
	int					length_field;
	int					precision;
	t_length			length_type;
	char				conv_indicator;
	va_list				arg;
}						t_format;


int			ft_vasprintf(char **ret, const char *s, va_list ap);
int			ft_printf(const char *s, ...);
int			search_next_format(const char *s);
void		resolve_format(char **ret, char *str, va_list ap);

#endif
