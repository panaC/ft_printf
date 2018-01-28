/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mae_parse.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:21:12 by pierre            #+#    #+#             */
/*   Updated: 2018/01/28 17:32:52 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "runner.h"

static int ma_01()
{
	t_format *t = init_struct();
	mae_attr("#d", t);
	RC(t->attr_dieze, 1);
	return (0);
}

static int ma_02()
{
	t_format *t = init_struct();
	mae_attr("-d", t);
	RC(t->attr_moins, 1);
	return (0);
}

static int ma_03()
{
	t_format *t = init_struct();
	mae_attr("+d", t);
	RC(t->attr_plus, 1);
	return (0);
}

static int ma_04()
{
	t_format *t = init_struct();
	mae_attr(" d", t);
	RC(t->attr_space, 1);
	return (0);
}

static int ma_05()
{
	t_format *t = init_struct();
	mae_attr("0d", t);
	RC(t->attr_0, 1);
	return (0);
}

static int ma_06()
{
	t_format *t = init_struct();
	mae_attr("d", t);
	RC(t->attr_dieze, 0);
	RC(t->attr_0, 0);
	RC(t->attr_space, 0);
	RC(t->attr_plus, 0);
	RC(t->attr_moins, 0);
	RC(t->attr_dieze, 0);
	return (0);
}

static int ma_07()
{
	t_format *t = init_struct();
	mae_attr("123d", t);
	RC(t->attr_dieze, 0);
	RC(t->attr_0, 0);
	RC(t->attr_space, 0);
	RC(t->attr_plus, 0);
	RC(t->attr_moins, 0);
	RC(t->attr_dieze, 0);
	return (0);
}

static int ma_08()
{
	t_format *t = init_struct();
	mae_attr("#0 +- +d", t);
	RC(t->attr_dieze, 1);
	RC(t->attr_0, 1);
	RC(t->attr_space, 1);
	RC(t->attr_plus, 1);
	RC(t->attr_moins, 1);
	RC(t->attr_dieze, 1);
	return (0);
}

static int		ma_test()
{
	PT;
	_verify(ma_01);
	_verify(ma_02);
	_verify(ma_03);
	_verify(ma_04);
	_verify(ma_05);
	_verify(ma_06);
	_verify(ma_07);
	_verify(ma_08);
	return (0);
}

int		mae_parse_test()
{
	return (ma_test());
}
