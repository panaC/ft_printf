/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_format.test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:05:24 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/29 13:51:45 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "runner.h"

static int mf_01__(t_format *t)
{
	char *s;
	s = mae_parse("#0 +- +      20.-10hda", t);
	char *d;
	d = mae_format(s, t);
	char *e = "+42                 ";
	RS(e, d);
	return (0);
}

static int mf_01_(int n, ...)
{
	t_format *t = init_struct();
	va_list ap;
	va_start(ap, n);
	va_copy(t->arg, ap);
	va_start(t->arg, n);
	return (mf_01__(t));
}

static int mf_01()
{
	return (mf_01_(0, 42));
}

static int mf_02__(t_format *t)
{
	char *s;
	s = mae_parse("#0 +- +      20.-10da", t);
	char *d;
	d = mae_format(s, t);
	char *e = "-94967296           ";
	RS(e, d);
	return (0);
}

static int mf_02_(int n, ...)
{
	t_format *t = init_struct();
	va_list ap;
	va_start(ap, n);
	va_copy(t->arg, ap);
	va_start(t->arg, n);
	return (mf_02__(t));
}

static int mf_02()
{
	return (mf_02_(0, 4200000000));
}

static int mf_03__(t_format *t)
{
	char *s;
	s = mae_parse("#0 +- +      20.-10Da", t);
	char *d;
	d = mae_format(s, t);
	char *e = "+4200000000         ";
	RS(e, d);
	return (0);
}

static int mf_03_(int n, ...)
{
	t_format *t = init_struct();
	va_list ap;
	va_start(ap, n);
	va_copy(t->arg, ap);
	va_start(t->arg, n);
	return (mf_03__(t));
}

static int mf_03()
{
	return (mf_03_(0, 4200000000));
}

static int mf_test()
{
	PT;
	_verify(mf_01);
	_verify(mf_02);
	_verify(mf_03);
	return (0);
}

static int mr_01__(t_format *t)
{
	char *e = ft_strdup("allo%#0 +- +      20.-10Da");
	char *s = "allo+42                 ";
	char *r = NULL;
	resolve_format(&r, e, t);
	RS(s, r);
	return (0);
}

static int mr_01_(int n, ...)
{
	t_format *t = init_struct();
	va_list ap;
	va_start(ap, n);
	va_copy(t->arg, ap);
	va_start(t->arg, n);
	return (mr_01__(t));
}

static int mr_01()
{
	return (mr_01_(0, 42));
}

static int mr_02__(t_format *t)
{
	char *e = ft_strdup("allo%#0 +- +      20.-10ma");
	char *s = "";
	char *r = NULL;
	resolve_format(&r, e, t);
	RS(s, r);
	return (0);
}

static int mr_02_(int n, ...)
{
	t_format *t = init_struct();
	va_list ap;
	va_start(ap, n);
	va_copy(t->arg, ap);
	va_start(t->arg, n);
	return (mr_02__(t));
}

static int mr_02()
{
	return (mr_02_(0, 42));
}

static int mr_03__(t_format *t)
{
	char *e = ft_strdup("allo");
	char *s = "allo";
	char *r = NULL;
	resolve_format(&r, e, t);
	RS(s, r);
	return (0);
}

static int mr_03_(int n, ...)
{
	t_format *t = init_struct();
	va_list ap;
	va_start(ap, n);
	va_copy(t->arg, ap);
	va_start(t->arg, n);
	return (mr_03__(t));
}

static int mr_03()
{
	return (mr_03_(0, 42));
}

static int mr_test()
{
	PT;
	_verify(mr_01);
	_verify(mr_02);
	_verify(mr_03);
	return (0);
}

int		resolve_format_test()
{
	return (mf_test() + mr_test());
}
