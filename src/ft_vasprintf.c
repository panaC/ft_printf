/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:56:04 by pierre            #+#    #+#             */
/*   Updated: 2018/01/24 18:19:36 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <libft.h>
#include "ft_printf.h"

/*
** Fonction Recursif printf
** 
** vasprintf permet de stocker le resultat dans une chaine de car alloue par la
** fonction : fonctionnement indentique printf
*/
int			ft_vasprintf(char **ret, const char *s, va_list ap)
{
	/*
	 * Recursivite de la fonction
	 *
	 * 1er etape/ parcourt de la chaine S :
	 * 		Tant que le code % n'est pas finis ou qu'il n'y en a pas :
	 * 			incrementation pointeur
	 * 		Si code finis ou \0 :
	 * 			copie de la difference pointeur fin - pointeur debut
	 *			Stockage de l'argument et passage a l'etape suivante
	 *	2eme etape / Si il reste des caractere dans la chaine :
	 *		Recursivite
	 *	3eme etape/ Si plus de caractere
	 *		return 
	 */

	size_t		size_end;
	va_list		arg;
	va_list		bck;
	char		*str;
	char		*str_recurs;

	printf("%d\n", search_next_format(s));
	if (((size_end = search_next_format(s))) == 0)
	{
		/* EOL */
		va_end(ap);
		*ret = ft_strdup("");
		return (0);
	}
	/* copie de la chaine de ptr_start a ptr_end*/
	str = ft_strsub(s, 0, size_end);
	/* sauvegarde de l'arg */
	va_copy(arg, ap);
	va_arg(ap, void*);
	/* copie va_list */
	va_copy(bck, ap);
	/* recursion */
	ft_vasprintf(&str_recurs, s + size_end, bck); /* size_end + 1 */
	/* 3eme etape */
	/*
	 * resolution du code suivant MAE
	 */
	/* concatenation avec ret precedement alloue */
	resolve_format(ret, str, arg);
	ft_strcat(*ret, str_recurs);
	ft_memdel((void**)&str_recurs);
	ft_memdel((void**)&str);
	va_end(ap);
	return (ft_strlen(*ret));
}
