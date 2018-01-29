/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:31:59 by pierre            #+#    #+#             */
/*   Updated: 2018/01/29 14:42:20 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include "runner.h"
#include "tddc.h"

int		tests_run = 0;

int		all_tests()
{
	int res = 0;
	res += param_test();
	res += format_d_test();
	res += mae_parse_test();
	res += resolve_format_test();
	res += ft_vasprintf_test();
	return (res);
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("RESULT : PASSED\n");
	printf("Tests run: %d\n", tests_run);

	return (result != 0);
}
